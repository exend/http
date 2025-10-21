#ifndef C357_NET_HTTP_RESPONSE_HPP
#define C357_NET_HTTP_RESPONSE_HPP

#include <c357/net/http/status.hpp>
#include <c357/net/http/header_map.hpp>
#include <istream>
#include <memory>

namespace c357::net::http {

/// Base class for all HTTP responses.
class response {
public:
	/// Indicates that body size is unknown (e.g. for open streams).
	static const size_t unknown_size;

	virtual ~response() = default;

	/// Creates a response with a status code and headers.
	response(status::code code, const header_map &headers);

	/// Creates a response with a status code and movable headers.
	response(status::code code, header_map &&headers);

	/// Creates a response with a status code only.
	response(status::code code);

	/// Returns HTTP status code.
	status::code status_code() const noexcept;

	/// Returns value of the given header.
	const std::string &header_value(const std::string &key) const;

	/// Sets or replaces a header.
	response &set_header(const std::string &key, const std::string &value);

	/// Returns all headers.
	const header_map &all_headers() const;

	/// Returns body size in bytes, or `0` if no body.
	/// Derived classes may return `unknown_size` for indeterminate streams.
	virtual size_t body_size() const;

	/// Returns input stream of the body.
	virtual std::istream &body_stream();

private:
	status::code code;
	header_map headers;
};

typedef std::shared_ptr<response> response_sptr;

}

#endif /* C357_NET_HTTP_RESPONSE_HPP */
