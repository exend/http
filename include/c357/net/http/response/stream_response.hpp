#ifndef C357_NET_HTTP_STREAM_RESPONSE_HPP
#define C357_NET_HTTP_STREAM_RESPONSE_HPP

#include <c357/net/http/response/response.hpp>
#include <memory>

namespace c357::net::http {

/// Response with body provided as an input stream.
class stream_response : public response {
public:
	/// Constructs response with given headers and body stream.
	stream_response(
	    status::code code,
	    const header_map &headers,
	    const std::shared_ptr<std::istream> &body_stream,
	    size_t body_size = response::unknown_size);

	/// Constructs response with no headers and provided body stream.
	stream_response(
	    status::code code,
	    const std::shared_ptr<std::istream> &body_stream,
	    size_t body_size = response::unknown_size);

	/// Returns specified body size or `unknown_size` if not determined.
	size_t body_size() const override;

	/// Returns stream containing response body.
	std::istream &body_stream() override;

private:
	size_t b_size;
	std::shared_ptr<std::istream> pbody_stream;
};

}

#endif /* C357_NET_HTTP_STREAM_RESPONSE_HPP */
