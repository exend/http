#ifndef C357_NET_HTTP_ROUTE_REGISTRY_HPP
#define C357_NET_HTTP_ROUTE_REGISTRY_HPP

#include <c357/net/http/request_handler.hpp>
#include <shared_mutex>

namespace c357::net::http {

/// Thread-safe registry of route handlers mapped by URL and HTTP method.
class route_registry {
	using url = base::util::url;

public:
	/// Registers a handler for a given route and method.
	void register_route_handler(
		const url &route,
		const method &method,
		const http_hndl_sptr &hndl);

	/// Finds handler for given route and method.
	http_hndl_sptr find_route_handler(
		const base::util::url &route,
		const method &method);

private:
	std::shared_mutex mtx;
	std::map<url, std::unordered_map<method, http_hndl_sptr>> routes;
	std::unordered_map<method, http_hndl_sptr> *find(const url &);
};

typedef std::shared_ptr<route_registry> route_registry_sptr;

}

#endif /* C357_NET_HTTP_ROUTE_REGISTRY_HPP */
