#include <c357/net/http/method.hpp>

using namespace std;
using namespace c357::net::http;

class method::mapping_error : public runtime_error {
	using runtime_error::runtime_error;
};

method::method(value val) noexcept
{
	this->val = val;
}

method::method(const string &val)
{
	this->val = map(val);
}

method::operator enum value() const noexcept {
	return val;
}

enum method::value method::map(const string &val)
{
	if (val == "GET")
		return value::get;
	if (val == "HEAD")
		return value::head;
	if (val == "POST")
		return value::post;
	if (val == "PUT")
		return value::put;
	if (val == "DELETE")
		return value::del;
	if (val == "CONNECT")
		return value::connect;
	if (val == "OPTIONS")
		return value::options;
	if (val == "TRACE")
		return value::trace;
	if (val == "PATCH")
		return value::patch;
	throw mapping_error("Failed to map: invalid HTTP method '" + val + '\'');
}
