## Roadmap of creating a socket
- create a socket - Get the file descriptor!
- bind to an address -What port am I on?
- listen on a port, and wait for a connection to be established.
- accept the connection from a client.
- send/recv - the same way we read and write for a file.
- shutdown to end read/write.
- close to releases data.

## Different types of sockets
- There are different types of socket to determine 
    the structure of the transport layer
- TCP(Streams)
- UDP(Datagrams)

## UDP(SOCK_DGRAM) are connectionless sockets
- There is no need for an open connection

1) Build a packet 
2) Put an IP header with destination info
3) Has SPEED advantage
4) Limited message size

## TCP (SOCK_STREAM)
1) Reliable two way connection
2) Works after connection established

## Server socket attributes
- Create a socket with socket()
- Socket is named after bind() call
- Client connects to named socket listen() for connections
- Accept a connection with accept()
- Receive requests with recv()
- send requests with send()

## Client socket attributes
- Create a socket with socket
- Connect the socket with the address of the server
- send and receive data with read() and write()

## Server functions
    
    fd = socket(AF_INET or AF_INET6, SOCK_STREAM or SOCK_DGRAM, 0 or 1 for internet connection) => outputs 0 or 1 
    bind(fd, sockaddr[(struct sockaddr *) &addr], sizeof(addr)[addrlen(size of struct)]) => bind the socket to a specific port
    listen(fd, backlog(max length of the queue for new connections))
    connect(fd, addr(pointer to struct sockaddr, addrlen(size of struct)))
    confd = accept(fd, &cliaddr, &cliaddrlen); cliaddr => client address
    
    // Reading data
    ssize_t = i;
    ssize_t rcount;
    char buf[BUFLEN=100];
    rcount = read(fd, buf, BUFLEN);
    write(fd, data="hello world", datalen=strlen(data));
    close(fd);
    
## Client Functions
    fd = socket(AF_INET or AF_INET6, SOCK_STREAM or SOCK_DGRAM, 0 or 1 for internet connection) => outputs 0 or 1 
    bind() => optional
    connect()
    write(), read()
    
## Important functions
    inet_pton() // to convert address
    htons() to // convert port
