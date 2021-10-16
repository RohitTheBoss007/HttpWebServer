#include "SimpleSocket.hpp"

//constructor
HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
	//define address structure
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interface);
	
	//establish socket
	sock = socket(domain, service, protocol);
	test_connection(sock);
	
}

//test connection virtual function
void HDE::SimpleSocket::test_connection(int item){
	
	//confirm that socket or connection has been properly established
	if(item<0){
		perror("Failed to connect...!!");
		exit(EXIT_FAILURE);
	}
}

//getter functions
struct sockaddr_in HDE::SimpleSocket::get_address(){
	return address;
}

int HDE::SimpleSocket::get_sock(){
		return sock;
}


int HDE::SimpleSocket::get_connection(){
		return connection;
}

//setter functions
void HDE::SimpleSocket::set_connection(int con){
		connection = con;
}

