# net::http

A lightweight C++ HTTP server library built on top of [`c357::net::core`](https://github.com/exend/netcore).

It provides essential components for handling HTTP requests, routing, and responses, without external dependencies.

## Features
- Simple request/response model
- Route-based request dispatching
- Stream and string-based responses
- Built-in default responses
- Optional request logging
- Built on top of the TCP abstraction layer (`net::core::server`, `connection`, etc.)

## Basic Structure
```
include/c357/net/http/
├── request/             # HTTP request types
├── response/            # Base and derived response types
├── route_registry.hpp   # Route handler registry
├── request_handler.hpp  # Interface for custom handlers
├── logger.hpp           # Logging interface
├── server.hpp           # HTTP server implementation
└── status.hpp           # HTTP status codes
```
## Example
```cpp
#include <c357/net/http/response/string_response.hpp>
#include <c357/net/http/route_registry.hpp>
#include <c357/net/http/server.hpp>
#include <csignal>
#include <atomic>

using namespace std;
using namespace c357::base::util;
using namespace c357::base::concurrent;
using namespace c357::net;
using namespace c357::net::core;
using namespace c357::net::http;

atomic_int signum = 0;

static void sighndl(int sign)
{
	signum = sign;
	signum.notify_all();
}

class hello_handler : public request_handler {
public:
	shared_ptr<response> handle(
	    const request &req,
	    cancellation_token token) override
	{
		return make_shared<string_response>(status::code::ok, "Hello, world!");
	}
};

int main(void)
{
	signal(SIGINT, sighndl);
	signal(SIGTERM, sighndl);
	route_registry_sptr reg = make_shared<route_registry>();
	reg->register_route_handler(url("/"), method::value::get, make_shared<hello_handler>());
	http::server srv(8080, reg, nullptr);
	srv.start();
	signum.wait(0);
	return 0;
}
```
## Build
```bash
git clone --recurse-submodules https://github.com/exend/http.git
cd http
cmake -B build
cmake --build build
```
Include in your project:
```cmake
add_subdirectory(http)
target_link_libraries(${PROJECT_NAME} PRIVATE http)
```
