#ifndef C357_NET_HTTP_REQUEST_DISPATCHER_HPP
#define C357_NET_HTTP_REQUEST_DISPATCHER_HPP


#include <c357/net/http/route_registry.hpp>
#include <c357/net/http/logger.hpp>
#include <c357/net/http/request/request.hpp>

namespace c357::net::http {

/// Dispatches HTTP requests to registered route handlers.
class request_dispatcher {
	using cancellation_token = base::concurrent::cancellation_token;

public:
	/// Constructs dispatcher with route registry and optional logger.
	request_dispatcher(route_registry_sptr, logger_sptr) noexcept;

	/// Finds handler for request and returns its response.
	response_sptr dispatch(const request &, cancellation_token);

private:
	route_registry_sptr registry;
	logger_sptr logger;
};

typedef std::shared_ptr<request_dispatcher> request_dispatcher_sptr;

}

#endif /* C357_NET_HTTP_REQUEST_DISPATCHER_HPP */
