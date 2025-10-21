#include <c357/net/http/status.hpp>

using namespace std;
using namespace c357::net::http;

string status::to_string(code status_code)
{
	switch (status_code) {
	case continue_:
		return "Continue";
	case switching_protocols:
		return "Switching Protocols";
	case processing:
		return "Processing";
	case early_hints:
		return "Early Hints";
	case ok:
		return "OK";
	case created:
		return "Created";
	case accepted:
		return "Accepted";
	case non_authoritative_information:
		return "Non-Authoritative Information";
	case no_content:
		return "No Content";
	case reset_content:
		return "Reset Content";
	case partial_content:
		return "Partial Content";
	case multi_status:
		return "Multi-Status";
	case already_reported:
		return "Already Reported";
	case im_used:
		return "IM Used";
	case multiple_choices:
		return "Multiple Choices";
	case moved_permanently:
		return "Moved Permanently";
	case found:
		return "Found";
	case see_other:
		return "See Other";
	case not_modified:
		return "Not Modified";
	case use_proxy:
		return "Use Proxy";
	case switch_proxy:
		return "Switch Proxy";
	case temporary_redirect:
		return "Temporary Redirect";
	case permanent_redirect:
		return "Permanent Redirect";
	case bad_request:
		return "Bad Request";
	case unauthorized:
		return "Unauthorized";
	case payment_required:
		return "Payment Required";
	case forbidden:
		return "Forbidden";
	case not_found:
		return "Not Found";
	case method_not_allowed:
		return "Method Not Allowed";
	case not_acceptable:
		return "Not Acceptable";
	case proxy_authentication_required:
		return "Proxy Authentication Required";
	case request_timeout:
		return "Request Timeout";
	case conflict:
		return "Conflict";
	case gone:
		return "Gone";
	case length_required:
		return "Length Required";
	case precondition_failed:
		return "Precondition Failed";
	case payload_too_large:
		return "Payload Too Large";
	case uri_too_long:
		return "url Too Long";
	case unsupported_media_type:
		return "Unsupported Media Type";
	case range_not_satisfiable:
		return "Range Not Satisfiable";
	case expectation_failed:
		return "Expectation Failed";
	case im_a_teapot:
		return "I'm a teapot";
	case misdirected_request:
		return "Misdirected Request";
	case unprocessable_content:
		return "Unprocessable Content";
	case locked:
		return "Locked";
	case failed_dependency:
		return "Failed Dependency";
	case too_early:
		return "Too Early";
	case upgrade_required:
		return "Upgrade Required";
	case precondition_required:
		return "Precondition Required";
	case too_many_requests:
		return "Too Many Requests";
	case request_header_fields_too_large:
		return "Request Header Fields Too Large";
	case unavailable_for_legal_reasons:
		return "Unavailable For Legal Reasons";
	case internal_server_error:
		return "Internal Server Error";
	case not_implemented:
		return "Not Implemented";
	case bad_gateway:
		return "Bad Gateway";
	case service_unavailable:
		return "Service Unavailable";
	case gateway_timeout:
		return "Gateway Timeout";
	case http_version_not_supported:
		return "HTTP Version Not Supported";
	case variant_also_negotiates:
		return "Variant Also Negotiates";
	case insufficient_storage:
		return "Insufficient Storage";
	case loop_detected:
		return "Loop Detected";
	case not_extended:
		return "Not Extended";
	case network_authentication_required:
		return "Network Authentication Required";
	}
}
