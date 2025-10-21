#include <c357/net/http/response/default_error_response.hpp>

using namespace std;
using namespace c357::net::http;

static string create_body_str(status::code err_code)
{
	string err_status(to_string(err_code) + " " + status::to_string(err_code));
	return "<html>"
	       "<head><title>" + err_status + "</title></head>"
	       "<body>"
	       "<center><h1>" + err_status + "</h1></center>"
	       "<hr><center>c357.httpserver</center>"
	       "</body>"
	       "</html>";
}

default_error_response::default_error_response(status::code err_code)
    : string_response(
          err_code,
          { { "Content-Type", "text/html; charset=utf-8" } },
          create_body_str(err_code))
{ }
