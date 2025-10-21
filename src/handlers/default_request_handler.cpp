#include "default_request_handler.hpp"
#include <c357/net/http/response/string_response.hpp>

using namespace std;
using namespace c357::base::concurrent;
using namespace c357::net::http;

response_sptr default_http_handler::handle(
    const request &request,
    cancellation_token token)
{
	return make_shared<string_response>(
	    status::code::ok,
	    "<html>"
	    "<head><title>c357.httpserver</title></head>"
	    "<body>"
	    "<center><h1>This is the default page.</h1></center>"
	    "<hr><center>c357.httpserver</center>"
	    "</body>"
	    "</html>");
}
