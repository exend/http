#ifndef C357_NET_HTTP_HTTPSERVER_HPP
#define C357_NET_HTTP_HTTPSERVER_HPP

#include <c357/net/core/server.hpp>
#include <c357/net/http/logger.hpp>
#include <c357/net/http/route_registry.hpp>

namespace c357::net::http {

class request_dispatcher;

class server : public core::server {
public:
	server(uint16_t port, route_registry_sptr &, const logger_sptr &);

private:
	std::shared_ptr<request_dispatcher> req_dispatcher;
	logger_sptr logger;
};

}

#endif /* C357_NET_HTTP_HTTPSERVER_HPP */
