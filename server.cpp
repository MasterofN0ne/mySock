#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


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

    Manually Creating an address:
        inet_pton() to convert address
        htons() to convert port

    ````
        struct sockaddr_in addr;
        inet_pton(AF_INET, "130.209.240.1", &addr.sin_addr);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
    ```
    Server functions:
            struct sockaddr{
                uint8_t sa_len;
                sa_family_t sa_family;
                char sa_data[22];
            };
        fd = socket(AF_INET or AF_INET6, SOCK_STREAM or SOCK_DGRAM, 0 or 1 for internet connection) => outputs 0 or 1 
        bind(fd, sockaddr[(struct sockaddr *) &addr], sizeof(addr)[addrlen(size of struct)]) => bind the socket to a specific port
        listen(fd, backlog(max length of the queue for new connections))
        connect(fd, addr(pointer to struct sockaddr, addrlen(size of struct)))
        confd = accept(fd, &cliaddr, &cliaddrlen); cliaddr => client address
        ssize_t = i;
        ssize_t rcount;
        char buf[BUFLEN=100];
        rcount = read(fd, buf, BUFLEN);
        write(fd, data="hello world", datalen=strlen(data));
        close(fd);
*/