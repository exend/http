#ifndef C357_NET_HTTP_DEFAULT_ERROR_RESPONSE_HPP
#define C357_NET_HTTP_DEFAULT_ERROR_RESPONSE_HPP

#include <c357/net/http/response/string_response.hpp>
#include <sstream>

namespace c357::net::http {

/// Simple string-based error response with predefined status text.
class default_error_response : public string_response {
public:
	/// Constructs error response with given status code.
	default_error_response(status::code err_code);
};

}

#endif /* C357_NET_HTTP_DEFAULT_ERROR_RESPONSE_HPP */
