#include "lib/common.h"

void read_data(int sockfd) {
    ssize_t n;
    char buf[1024];

    int time = 0;
    for(;;) {
        fprintf(stdout, "block in read\n")
        if ((n = readn(sockfd, buf, 1024)) == 0)
        {
            retun;
        }

        time++;
        fprintf(stdout, "1K read for %d \n", time)
        usleep(1000)
    }
}

int main(int argc, char const *argv[])
{
    int listenfd, connfd;
    socklen_t client;
    struct sockaddr_in cliaddr, servaddr;

    // create socket 
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons (12345);
    servaddr.sin_addr.s_addr = htonl (INADDR_ANY);

    // bind
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listenfd, 1024);
    
    for (;;)
    {
        client = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr));
        read_data(connfd);
        close(connfd);
    }
    

    return 0;
}
