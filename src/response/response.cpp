#include <c357/net/http/response/response.hpp>
#include <sstream>
#include <limits>

using namespace std;
using namespace c357::net::http;

const size_t response::unknown_size = std::numeric_limits<size_t>::max();

response::response(status::code code, const header_map &headers)
    : code(code)
    , headers(headers)
{ }

response::response(status::code code, header_map &&headers)
    : code(code)
    , headers(std::move(headers))
{ }

response::response(status::code code)
    : response(code, {})
{ }

status::code response::status_code() const noexcept
{
	return code;
}

const string &response::header_value(const string &key) const
{
	return headers.at(key);
}

response &response::set_header(const string &key, const string &value)
{
	headers[key] = value;
	return *this;
}

const header_map &response::all_headers() const
{
	return headers;
}

size_t response::body_size() const
{
	return 0L;
}

istream &response::body_stream()
{
	static istringstream empty("");
	return empty;
}
