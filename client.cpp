#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>


int main(){
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (fd == -1)
        std::cout << "Error unable to create socket.." << std::endl;
    return 0;
}