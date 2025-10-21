#ifndef C357_NET_HTTP_HEADER_MAP_HPP
#define C357_NET_HTTP_HEADER_MAP_HPP

#include <string>
#include <unordered_map>

namespace c357::net::http {

/// Represents a collection of HTTP headers as key-value pairs.
typedef std::unordered_map<std::string, std::string> header_map;

}

#endif /* C357_NET_HTTP_HEADER_MAP_HPP */
