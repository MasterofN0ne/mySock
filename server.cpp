#include <iostream>

/* 
    Roadmap of this project
    - create a socket - Get the file descriptor!
    - bind to an address -What port am I on?
    - listen on a port, and wait for a connection to be established.
    - accept the connection from a client.
    - send/recv - the same way we read and write for a file.
    - shutdown to end read/write.
    - close to releases data.
*/



/* 
        There are different types of socket to determine 
    the structure of the transport layer

    - TCP(Streams)
    - UDP(Datagrams)

    UDP are connectionless sockets
        There is no need for an open connection
        1) Build a packet
        2) Put an IP header with destination info
        Speed!!!
        limited message size 
        can send regardless of network state
        SOCK_DGRAM


    TCP
        SOCK_STREAM
        Reliable two way connection
        Works after connection establish

*/

/*
    Server socket attributes
        Create a socket with socket()
        Socket is named after bind() call
        Client connects to named socket listen() for connections
        Accept a connection with accept()
        Receive requests with recv()
        send requests with send()

    Client socket attributes
        Create a socket with socket
        Connect the socket with the address of the server
        send and receive data with read() and write()


    functions to be used 
        int socket(int domain, int type, int protocol);
        domain = AF_INET, AF_INET6
*/