#ifndef C357_NET_HTTP_REQUEST_HPP
#define C357_NET_HTTP_REQUEST_HPP

#include <c357/base/util/url.hpp>
#include <c357/net/http/header_map.hpp>
#include <c357/net/http/method.hpp>
#include <c357/net/http/version.hpp>
#include <map>
#include <memory>
#include <ostream>
#include <string>

namespace c357::net::http {

struct request final {
	http::method method;
	base::util::url url;
	http::version version;
	header_map headers;
	std::shared_ptr<std::istream> body_stream;

	inline request(
	    http::method method,
	    const base::util::url &url,
	    http::version version,
	    const header_map &headers,
	    const std::shared_ptr<std::istream> &body_stream);
	inline request(
	    http::method method,
	    base::util::url &&url,
	    http::version version,
	    header_map &&headers,
	    const std::shared_ptr<std::istream> &body_stream = nullptr);
	request() noexcept = default;
};

inline request::request(
    http::method method,
    const base::util::url &url,
    http::version version,
    const header_map &headers,
    const std::shared_ptr<std::istream> &body_stream)
    : method(method)
    , url(url)
    , version(version)
    , headers(headers)
    , body_stream(body_stream)
{ }

inline request::request(
    http::method method,
    base::util::url &&url,
    http::version version,
    header_map &&headers,
    const std::shared_ptr<std::istream> &body_stream)
    : method(method)
    , url(std::move(url))
    , version(version)
    , headers(std::move(headers))
    , body_stream(body_stream)
{ }

}

#endif /* C357_NET_HTTP_REQUEST_HPP */
