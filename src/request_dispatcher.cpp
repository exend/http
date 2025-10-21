#include "request_dispatcher.hpp"
#include <c357/net/http/response/default_error_response.hpp>

using namespace std;
using namespace c357::net::http;

request_dispatcher::request_dispatcher(
    route_registry_sptr reg,
    logger_sptr logger) noexcept
    : registry(reg)
    , logger(logger)
{ }

response_sptr request_dispatcher::dispatch(const request &req, cancellation_token ctoken)
{
	try {
		http_hndl_sptr hndl = registry->find_route_handler(req.url, req.method);
		if (hndl) {
			return hndl->handle(req, ctoken);
		} else {
			return make_shared<default_error_response>(status::code::not_found);
		}
	} catch (...) {
		if (logger)
			logger->log_error(current_exception());
		return make_shared<default_error_response>(status::code::internal_server_error);
	}
}
