#ifndef C357_NET_HTTP_PROTOCOL_HANDLER_HPP
#define C357_NET_HTTP_PROTOCOL_HANDLER_HPP

#include <c357/net/core/app_protocol_handler.hpp>
#include <cstdint>
#include <string>
#include <vector>
#include <istream>
#include "default_request_handler.hpp"
#include "../request_dispatcher.hpp"

namespace c357::net::http {

class http_protocol_handler : public core::app_protocol_handler {
public:
	http_protocol_handler(
	    const request_dispatcher_sptr &req_dispatcher,
	    const std::shared_ptr<logger> &logger) noexcept;
	void handle(
	    std::shared_ptr<core::connection> conn,
	    base::concurrent::cancellation_token token) override;
	void handle(std::exception_ptr exc) noexcept override;

private:
	request_dispatcher_sptr req_dispatcher;
	logger_sptr plogger;
	default_http_handler default_http_hndl;
};

}

#endif /* C357_NET_HTTP_PROTOCOL_HANDLER_HPP */
