#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>


int main(){
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;


    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1){
        std::cout << "Can't connect to the server.." << std::endl;
        exit(0);
    }
    char server_message[2048];

    recv(network_socket, server_message, sizeof(server_message), 0);

    std::cout << server_message << std::endl;

    close(network_socket);
    return 0;
}