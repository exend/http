#include <c357/net/http/route_registry.hpp>
#include <cstring>
#include <mutex>

using namespace std;
using namespace c357::base::util;
using namespace c357::net::http;

void route_registry::register_route_handler(
	const url &route,
	const method &method,
	const http_hndl_sptr &hndl)
{
	unique_lock lock(mtx);
	routes[route][method] = hndl;
}

http_hndl_sptr route_registry::find_route_handler(
	const url &route,
	const method &method)
{
	shared_lock lock(mtx);
	auto methods = find(route);
	if (methods == nullptr)
		return nullptr;
	auto it = methods->find(method);
	if (it == methods->end())
		return nullptr;
	return it->second;
}

unordered_map<method, http_hndl_sptr> *route_registry::find(const url &requri)
{
	const string &requristr = requri.abs_string();
	auto it = routes.upper_bound(requri);
	if (it != routes.begin()) {
		do {
			--it;
			const string &route = it->first.abs_string();
			if (!requristr.starts_with(route))
				continue;
			if (requristr.length() > route.length() && route.back() != '/')
				if (!strchr("/?#", requristr.at(route.length())))
					continue;
			return &it->second;
		} while (it != routes.begin());
	}
	return nullptr;
}
