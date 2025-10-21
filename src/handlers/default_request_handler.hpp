#ifndef C357_NET_HTTP_DEFAULT_REQUEST_HANDLER_HPP
#define C357_NET_HTTP_DEFAULT_REQUEST_HANDLER_HPP

#include <c357/net/http/request_handler.hpp>

namespace c357::net::http {

/// Default HTTP handler used when no route handlers are registered.
/// Generates a minimal HTML page with text "This is the default page."
class default_request_handler : public request_handler {
public:
	/// Returns a default HTML response when route registry is empty.
	response_sptr handle(
	    const request &request,
	    base::concurrent::cancellation_token token) override;
};

}

#endif /* C357_NET_HTTP_DEFAULT_REQUEST_HANDLER_HPP */
