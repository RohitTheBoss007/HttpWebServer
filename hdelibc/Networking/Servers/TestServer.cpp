#include "TestServer.hpp"
using namespace std;
HDE::TestServer::TestServer():SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10){
		launch();
}

void HDE::TestServer::accepter(){
		struct sockaddr_in address = get_socket()->get_address();
		int addrlen = sizeof(address);
		new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
		read(new_socket, buffer, 30000);
}

void HDE::TestServer::handler(){
		cout<<buffer<<endl;
}

void HDE::TestServer::responder(){
		char *hello = "Hello from server"; 
		write(new_socket, hello, strlen(hello));
		close(new_socket);
}
void HDE::TestServer::launch(){
		while(true){
			cout<<"===== WAITING ====="<<endl;
			accepter();
			handler();
			responder();
			cout<<"===== DONE ====="<<endl;
		}
}
