#ifndef C357_NET_HTTP_LOGGER_H
#define C357_NET_HTTP_LOGGER_H

#include <c357/net/core/ip_address.hpp>
#include <c357/net/http/request/request.hpp>
#include <c357/net/http/response/response.hpp>
#include <exception>

namespace c357::net::http {

/// Logging interface for HTTP server events.
class logger {
public:
	virtual ~logger() = default;

	/// Logs a successful response.
	virtual void log_response(
	    const core::ip_address &ip,
	    const request &req,
	    const response &resp)
	    = 0;

	/// Logs an exception.
	virtual void log_error(std::exception_ptr eptr) = 0;
};

typedef std::shared_ptr<logger> logger_sptr;

}

#endif /* C357_NET_HTTP_LOGGER_H */
