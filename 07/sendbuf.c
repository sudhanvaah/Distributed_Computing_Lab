#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char **argv)
{
 int sockfd, sendbuff;
 socklen_t optlen;

 sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 int res = 0;
 optlen = sizeof(sendbuff);
 res = getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sendbuff, &optlen);
 printf("send buffer size = %d\n", sendbuff);
 sendbuff = 20480;
 printf("sets the send buffer to %d\n", sendbuff);
 res = setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sendbuff, sizeof(sendbuff));
 optlen = sizeof(sendbuff);
 res = getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &sendbuff, &optlen);
 printf("send buffer size = %d\n", sendbuff);
 
 return 0;
}
