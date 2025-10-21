#ifndef C357_NET_HTTP_RESPONSE_HPP
#define C357_NET_HTTP_RESPONSE_HPP

#include <c357/net/http/status.hpp>
#include <c357/net/http/header_map.hpp>
#include <istream>
#include <memory>

namespace c357::net::http {

class response {
public:
	static const size_t unknown_size;

	response(status::code code, const header_map &headers);
	response(status::code code, header_map &&headers);
	response(status::code code);
	virtual ~response() = default;
	status::code status_code() const noexcept;
	const std::string &header_value(const std::string &key) const;
	response &set_header(const std::string &key, const std::string &value);
	const header_map &all_headers() const;
	virtual size_t body_size() const;
	virtual std::istream &body_stream();

private:
	status::code code;
	header_map headers;
};

typedef std::shared_ptr<response> response_sptr;

}

#endif /* C357_NET_HTTP_RESPONSE_HPP */
