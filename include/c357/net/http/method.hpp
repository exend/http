#ifndef C357_NET_HTTP_METHOD_HPP
#define C357_NET_HTTP_METHOD_HPP

#include <stdexcept>
#include <string>

namespace c357::net::http {

struct method final {
	class mapping_error;

	enum class value {
		get,
		head,
		post,
		put,
		del,
		connect,
		options,
		trace,
		patch
	};

	method() noexcept = default;
	method(value val) noexcept;
	method(const std::string &val);
	operator enum value() const noexcept;
	auto operator<=>(const method &) const noexcept = default;

private:
	enum value val = value::get;
	static enum value map(const std::string &val);
};

}

template<>
struct std::hash<c357::net::http::method> {
	size_t operator()(const c357::net::http::method &m) const noexcept {
		return std::hash<c357::net::http::method::value>()(m);
	}
};

#endif /* C357_NET_HTTP_METHOD_HPP */
