#ifndef C357_NET_HTTP_STRING_RESPONSE_HPP
#define C357_NET_HTTP_STRING_RESPONSE_HPP

#include <c357/net/http/response/response.hpp>
#include <sstream>

namespace c357::net::http {

class string_response : public response {
public:
	string_response(
	    status::code code,
	    const header_map &headers,
	    const std::string &str);
	string_response(
	    status::code code,
	    header_map &&headers,
	    std::string &&str);
	string_response(
	    status::code code,
	    const std::string &str);
	string_response(
	    status::code code,
	    std::string &&str);
	size_t body_size() const override;
	std::istream &body_stream() override;

private:
	size_t size;
	std::istringstream body_str_stream;
};

}

#endif /* C357_NET_HTTP_STRING_RESPONSE_HPP */
