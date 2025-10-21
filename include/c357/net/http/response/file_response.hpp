#ifndef C357_NET_HTTP_FILE_RESPONSE_HPP
#define C357_NET_HTTP_FILE_RESPONSE_HPP

#include <c357/net/http/response/stream_response.hpp>
#include <fstream>

namespace c357::net::http {

class file_response : public stream_response {
public:
	file_response(
	    status::code code,
	    const header_map &headers,
	    const std::shared_ptr<std::ifstream> &body_stream);
	file_response(
	    status::code code,
	    const std::shared_ptr<std::ifstream> &body_stream);
};

}

#endif /* C357_NET_HTTP_FILE_RESPONSE_HPP */
