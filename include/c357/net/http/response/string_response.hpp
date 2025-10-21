#ifndef C357_NET_HTTP_STRING_RESPONSE_HPP
#define C357_NET_HTTP_STRING_RESPONSE_HPP

#include <c357/net/http/response/response.hpp>
#include <sstream>

namespace c357::net::http {

/// Response with a body stored as a string.
class string_response : public response {
public:
	/// Constructs from code, headers and string body.
	string_response(
	    status::code code,
	    const header_map &headers,
	    const std::string &body);

	/// Constructs from code, movable headers and movable string body.
	string_response(
	    status::code code,
	    header_map &&headers,
	    std::string &&body);

	/// Constructs from code and string body.
	string_response(
	    status::code code,
	    const std::string &body);

	/// Constructs from code and movable string body.
	string_response(
	    status::code code,
	    std::string &&body);
	size_t body_size() const override;

	/// Returns input stream of the string body.
	std::istream &body_stream() override;

private:
	size_t size;
	std::istringstream body_str_stream;
};

}

#endif /* C357_NET_HTTP_STRING_RESPONSE_HPP */
