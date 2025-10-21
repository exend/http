#ifndef C357_NET_HTTP_NOT_FOUND_RESPONSE_HPP
#define C357_NET_HTTP_NOT_FOUND_RESPONSE_HPP

#include <c357/net/http/response/response.hpp>
#include <sstream>

namespace c357::net::http {

class not_found_response : public response {
public:
	not_found_response();
	size_t body_size() const override;
	std::istream &body_stream() override;

private:
	static const std::string err_str;
	std::istringstream body_str_stream;
};

}

#endif /* C357_NET_HTTP_NOT_FOUND_RESPONSE_HPP */
