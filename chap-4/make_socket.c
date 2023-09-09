#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>


int make_socket (u_int16_t port) 
{
    int sock;
    struct sockaddr_in name;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error");
        exit(EXIT_FAILURE);
    }

    name.sin_family = AF_INET;
    name.sin_port = htons (port);
    name.sin_addr.s_addr = htonl (INADDR_ANY);

    if (bind(sock, (struct sockaddr *) &name, sizeof(name) < 0) < 0)
    {
        perror("error");
        exit(EXIT_FAILURE);
    }
    

    return sock;
}

int main(int argc, char const *argv[])
{
    
    int sockfd = make_socket(12345);
    exit(0);
}
