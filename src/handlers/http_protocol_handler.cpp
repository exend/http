#include "http_protocol_handler.hpp"
#include <c357/net/core/connection.hpp>
#include <c357/net/http/request/request.hpp>
#include <c357/net/http/response/default_error_response.hpp>
#include <exception>

using namespace std;
using namespace c357::base::concurrent;
using namespace c357::base::util;
using namespace c357::net;
using namespace core;
using namespace http;

class fmt_error : public runtime_error {
	using runtime_error::runtime_error;
};

static http::method read_method(istream &stream)
{
	string method_str;
	stream >> method_str;
	return http::method(method_str);
}

static url read_uri(istream &stream)
{
	string uri_str;
	stream >> uri_str;
	return url(uri_str);
}

static http::version read_version(istream &stream)
{
	string buf;
	char ch;
	uint8_t major;
	uint8_t minor{0};
	getline(stream, buf, '/');
	if (buf != " HTTP")
		throw fmt_error("Format error: Not HTTP request");
	stream >> major;
	if (stream >> ch && ch == '.')
		stream >> minor;
	stream.ignore(numeric_limits<streamsize>::max(), '\n');
	return version(major, minor);
}

static header_map read_headers(istream &stream)
{
	header_map headers;
	string key;
	string val;
	while (!isspace(stream.peek())) {
		getline(stream, key, ':');
		stream.ignore();
		getline(stream, val);
		if (val.back() == '\r')
			val.pop_back();
		headers[key] = val;
	}
	stream.ignore(numeric_limits<streamsize>::max(), '\n');
	return headers;
}

static http::request parse_request(shared_ptr<iostream> stream)
{
	return http::request(
	    read_method(*stream),
	    read_uri(*stream),
	    read_version(*stream),
	    read_headers(*stream),
	    stream);
}

static void send(http::response &response, ostream &os, cancellation_token token)
{
	if (token.is_cancellation_requested())
		return;
	status::code code = response.status_code();
	string status = to_string(code) + " " + status::to_string(code);
	string headers;
	for (const auto &[key, value] : response.all_headers())
		headers.append(key + ": " + value + "\r\n");
	os << "HTTP/1.1 " << status << "\r\n";
	os << headers << "\r\n";

	if (response.body_size() == 0)
		return;
	istream &bs = response.body_stream();
	char buf[4096];
	while (bs.read(buf, sizeof(buf)) || bs.gcount() > 0) {
		os.write(buf, bs.gcount());
		if (token.is_cancellation_requested())
			break;
	}
}

http_protocol_handler::http_protocol_handler(
    const request_dispatcher_sptr &req_dispatcher,
    const shared_ptr<logger> &logger) noexcept
    : req_dispatcher(req_dispatcher)
    , plogger(logger)
{ }

void http_protocol_handler::handle(
	shared_ptr<connection> conn,
	cancellation_token cancel_token)
{
	if (!conn->is_open() || cancel_token.is_cancellation_requested())
		return;

	shared_ptr<iostream> stream = conn->iostream();
	request req;
	response_sptr resp;

	try {
		req = parse_request(stream);
	} catch (...) {
		if (plogger)
			plogger->log_error(current_exception());
		resp = make_shared<default_error_response>(status::code::bad_request);
	}

	if (!resp && !req.headers.contains("Host"))
		resp = make_shared<default_error_response>(status::code::bad_request);

	if (!resp) {
		try {
			resp = req_dispatcher->dispatch(req, cancel_token);
		} catch (...) {
			if (plogger)
				plogger->log_error(current_exception());
			resp = make_shared<default_error_response>(status::code::internal_server_error);
		}
	}

	size_t body_size = resp->body_size();
	if (body_size && body_size != response::unknown_size)
		resp->set_header("Content-Length", to_string(body_size));
	resp->set_header("Connection", "close");
	resp->set_header("Server", "c357.httpserver");

	try {
		send(*resp, *stream, cancel_token);
		if (plogger)
			plogger->log_response(conn->ip(), req, *resp);
	} catch (exception &e) {
		if (plogger)
			plogger->log_error(current_exception());
	}
	conn->close();
}

void http_protocol_handler::handle(exception_ptr e) noexcept
{
	try {
		if (plogger)
			plogger->log_error(e);
	} catch (...) {
		// deal with it
	}
}
