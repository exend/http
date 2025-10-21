#ifndef C357_NET_HTTP_REQUEST_HANDLER_HPP
#define C357_NET_HTTP_REQUEST_HANDLER_HPP

#include <c357/base/concurrent/cancellation_token.hpp>
#include <c357/net/http/response/response.hpp>
#include <c357/net/http/request/request.hpp>
#include <memory>

namespace c357::net::http {

/// Base interface for handling HTTP requests.
struct request_handler {
	virtual ~request_handler() = default;

	/// Handles a request and returns a response.
	virtual std::shared_ptr<response> handle(
	    const request &request,
	    base::concurrent::cancellation_token token) = 0;
};

typedef std::shared_ptr<request_handler> http_hndl_sptr;

}

#endif /* C357_NET_HTTP_REQUEST_HANDLER_HPP */
