#include <c357/net/http/server.hpp>
#include "handlers/http_protocol_handler.hpp"
#include "request_dispatcher.hpp"

using namespace std;
using namespace c357::base::util;
using namespace c357::net;
using namespace http;
using namespace core;

static app_proto_hndl_reg create_reg(
	uint16_t port,
	const route_registry_sptr &route_reg,
	const logger_sptr &logger)
{
	try {
		app_proto_hndl_reg hndl_reg;
		auto hndl = make_shared<http_protocol_handler>(
		    make_shared<request_dispatcher>(route_reg, logger),
		    logger);
		hndl_reg.register_handler(port, hndl);
		return hndl_reg;
	} catch (...) {
		if (logger)
			logger->log_error(current_exception());
		rethrow_exception(current_exception());
	}
}

http::server::server(
    uint16_t port,
    route_registry_sptr &registry,
    const logger_sptr &logger)
    : core::server(create_reg(port, registry, logger))
    , req_dispatcher(make_shared<request_dispatcher>(registry, logger))
    , logger(logger)
{ }
