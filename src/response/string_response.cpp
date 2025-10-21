#include <c357/net/http/response/string_response.hpp>

using namespace std;
using namespace c357::net::http;

string_response::string_response(
    status::code code,
    const header_map &headers,
    const string &str)
    : response(code, headers)
    , size(str.size())
    , body_str_stream(str)
{ }

string_response::string_response(
    status::code code,
    header_map &&headers,
    string &&str)
    : response(code, std::move(headers))
    , size(str.size())
    , body_str_stream(std::move(str))
{ }

string_response::string_response(
    status::code code,
    const string &str)
    : response(code)
    , size(str.size())
    , body_str_stream(str)
{ }

string_response::string_response(
    status::code code,
    string &&str)
    : response(code)
    , size(str.size())
    , body_str_stream(std::move(str))
{ }

size_t string_response::body_size() const
{
	return size;
}

istream &string_response::body_stream()
{
	return body_str_stream;
}
