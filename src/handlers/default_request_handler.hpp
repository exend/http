#ifndef C357_NET_HTTP_DEFAULT_REQUEST_HANDLER_HPP
#define C357_NET_HTTP_DEFAULT_REQUEST_HANDLER_HPP

#include <c357/net/http/request_handler.hpp>

namespace c357::net::http {

class default_http_handler : public http_handler {
public:
	response_sptr handle(
	    const request &request,
	    base::concurrent::cancellation_token token) override;
};

}

#endif /* C357_NET_HTTP_DEFAULT_REQUEST_HANDLER_HPP */
