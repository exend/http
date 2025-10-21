#ifndef C357_NET_HTTP_REQUEST_HANDLER_HPP
#define C357_NET_HTTP_REQUEST_HANDLER_HPP

#include <c357/base/concurrent/cancellation_token.hpp>
#include <c357/net/http/response/response.hpp>
#include <c357/net/http/request/request.hpp>
#include <memory>

namespace c357::net::http {

struct http_handler {
	virtual ~http_handler() = default;
	virtual std::shared_ptr<response> handle(
	    const request &request,
	    base::concurrent::cancellation_token token) = 0;
};

typedef std::shared_ptr<http_handler> http_hndl_sptr;

}

#endif /* C357_NET_HTTP_REQUEST_HANDLER_HPP */
