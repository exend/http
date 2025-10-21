#include <c357/net/http/response/file_response.hpp>

using namespace std;
using namespace c357::net::http;

static size_t file_size(ifstream &fs)
{
	ios::iostate state = fs.rdstate();
	streampos curpos = fs.tellg();
	streampos begpos = fs.seekg(0, ios::beg).tellg();
	streampos endpos = fs.seekg(0, ios::end).tellg();
	fs.seekg(curpos, ios::beg);
	fs.clear(state);
	return endpos - begpos;
}

file_response::file_response(
    status::code code,
    const header_map &headers,
    const shared_ptr<ifstream> &stream)
    : stream_response(code, headers, stream, file_size(*stream))
{ }

file_response::file_response(
	status::code code,
	const shared_ptr<ifstream> &stream)
	: stream_response(code, stream, file_size(*stream))
{ }
