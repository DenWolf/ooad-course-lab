#include "HTTPView.h"


#include <signal.h>


#include "HTTPException.h"
#include "SocketException.h"
#include "StatusHTTPException.h"

#include "request.h"
#include "send.h"


#include <type_traits>
#include "../../utils/formatTypeidName.h"




//using std::string;




/*static
map<string, string> init_from_array() {
  map<string, string> m;
	m.insert(make_pair("/", "html/index.htm"));
	m.insert(make_pair("/main.css", "html/main.css"));
	return m;
}*/






static
SOCKET current_socket;

static
bool has_control_c_pressed = false;

static
void on_control_c_pressed(int) { // shortly double hit ctrl^c causes abort() message
	closesocket(current_socket);
	has_control_c_pressed = true;
}







HTTPView::HTTPView() /*: path_to_file(init_from_array())*/ {
  WSADATA wd;
  struct servent const *http;
  union {sockaddr a; sockaddr_in i;} addr;

  void (*prev_signal)(int) = signal(SIGINT, on_control_c_pressed); // may be not thread safe (races)
	if (prev_signal != SIG_DFL)
		throw HTTPException("only one server can exist in one time");


	if (WSAStartup(MAKEWORD(1, 1), &wd))
		throw SocketException("in WSAStartup");

	if ((http = getservbyname("http", "tcp")) == NULL)
		throw SocketException("in getservbyname");

	memset(&addr, 0, sizeof addr);
	addr.i.sin_family = AF_INET;
	addr.i.sin_port = http->s_port;
	addr.i.sin_addr.s_addr = htonl(INADDR_ANY);

	if ((s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		throw SocketException("in socket creation");

	if (bind(s, &addr.a, sizeof addr.a))
		throw SocketException("in bind");
}




HTTPView::~HTTPView() {
	signal(SIGINT, SIG_DFL);

	if (closesocket(s))
		if (!has_control_c_pressed)
			throw SocketException("in closesocket");

	if (WSACleanup())
		throw SocketException("in WSACleanup");
}























#include <iostream>

using std::cout;
using std::endl;


void HTTPView::server() {
  SOCKET a = INVALID_SOCKET;
  union {sockaddr a; sockaddr_in i;} addr;
  int addr_len;


	if (listen(s, 2))
		throw SocketException("can't listen");

	for (;;) {
		try {
			addr_len = sizeof addr.a;
			memset(&addr, 0, sizeof addr.a);

			current_socket = s; // global variable
			if ((a = accept(s, &addr.a, &addr_len)) == INVALID_SOCKET) {
				throw SocketException("in accept");
			}

			cout << "accept" << endl;


		  Request request = Request::receive(a);
			cout << "request\n";
			cout << "\t\"" << request.type << "\"\n";
			cout << "\t\"" << request.path << '\"' << endl;
			cout << '{';
			cout << request.all;
			cout << '}' << endl;

			/*if (request.type == "GET") {
				auto found = path_to_file.find(request.path);
				if (found != path_to_file.end()) {
					send_response(a, 200);
					send_file(a, found->second);
					cout << "sended\n";
					cout << "\t\"" << found->second << '\"' << endl;
				} else {
					send_response(a, 404);
					cout << "\t" "resource not found" << endl;
				}
			} else if (request.type == "POST") {
				if (request.path == "/login") {

				} else
					throw NotFoundException("unknown request path");
			} else
				throw NotImplementedException("unknown request type");*/
		} catch (const SocketException &e) {
			if (has_control_c_pressed) { // global variable
				closesocket(a); a = INVALID_SOCKET;
				break;
			}
			cout << "\t" "SocketException: " << e.what() << endl;
		} catch (const StatusHTTPException &e) {
			cout << "\t" "StatusHTTPException: " << formatTypeidName(typeid(e).name()) << ": \n";
			cout << "\t" "status: " << e.getStatus() << '\n';
			cout << "\t" "what: " << e.what() << endl;

			send_response(a, e.getStatus());
			cout << "sended response" << endl;
		}

		cout << "close\n";
		{
			int res = closesocket(a);
			a = INVALID_SOCKET;
			if (res)
				throw SocketException("in closesocket");
		}
	}
}





