#ifndef C357_NET_HTTP_STREAM_RESPONSE_HPP
#define C357_NET_HTTP_STREAM_RESPONSE_HPP

#include <c357/net/http/response/response.hpp>
#include <memory>

namespace c357::net::http {

class stream_response : public response {
public:
	stream_response(
	    status::code code,
	    const header_map &headers,
	    const std::shared_ptr<std::istream> &body_stream,
	    size_t body_size = response::unknown_size);
	stream_response(
	    status::code code,
	    const std::shared_ptr<std::istream> &body_stream,
	    size_t body_size = response::unknown_size);
	size_t body_size() const override;
	std::istream &body_stream() override;

private:
	size_t b_size;
	std::shared_ptr<std::istream> pbody_stream;
};

}

#endif /* C357_NET_HTTP_STREAM_RESPONSE_HPP */
