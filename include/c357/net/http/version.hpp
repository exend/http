#ifndef C357_NET_HTTP_VERSION_HPP
#define C357_NET_HTTP_VERSION_HPP

#include <cstdint>

namespace c357::net::http {

/// Represents HTTP version (e.g. 1.0, 1.1).
struct version {
	uint8_t major;
	uint8_t minor;
	version(uint8_t major, uint8_t minor) noexcept
		: major(major)
		, minor(minor)
	{ }
	version() noexcept = default;
	version(const version &) noexcept = default;
	auto operator<=>(const version &) const noexcept = default;
};

}

#endif /* C357_NET_HTTP_VERSION_HPP */
