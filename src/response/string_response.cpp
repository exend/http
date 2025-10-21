#include <c357/net/http/response/string_response.hpp>

using namespace std;
using namespace c357::net::http;

string_response::string_response(
    status::code code,
    const header_map &headers,
    const string &body)
    : response(code, headers)
    , size(body.size())
    , body_str_stream(body)
{ }

string_response::string_response(
    status::code code,
    header_map &&headers,
    string &&body)
    : response(code, std::move(headers))
    , size(body.size())
    , body_str_stream(std::move(body))
{ }

string_response::string_response(
    status::code code,
    const string &body)
    : response(code)
    , size(body.size())
    , body_str_stream(body)
{ }

string_response::string_response(
    status::code code,
    string &&body)
    : response(code)
    , size(body.size())
    , body_str_stream(std::move(body))
{ }

size_t string_response::body_size() const
{
	return size;
}

istream &string_response::body_stream()
{
	return body_str_stream;
}
