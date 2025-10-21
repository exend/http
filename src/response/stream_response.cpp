#include <c357/net/http/response/stream_response.hpp>

using namespace std;
using namespace c357::net::http;

stream_response::stream_response(
    status::code code,
    const header_map &headers,
    const shared_ptr<istream> &body_stream,
    size_t body_size
)
    : response(code, headers)
    , b_size(body_size)
    , pbody_stream(body_stream)
{ }

stream_response::stream_response(
    status::code code,
    const shared_ptr<istream> &body_stream,
    size_t body_size
)
    : response(code)
    , b_size(body_size)
    , pbody_stream(body_stream)
{ }

size_t stream_response::body_size() const
{
	return b_size;
}

istream &stream_response::body_stream()
{
    return *pbody_stream;
}
