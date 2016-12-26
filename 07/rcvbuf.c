#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char **argv)
{
 int sockfd, sendbuff;
 socklen_t optlen;

 sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 if(sockfd == -1)
     printf("Error");

 int res = 0;

 // Get buffer size
 optlen = sizeof(sendbuff);
 res = getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &sendbuff, &optlen);

 if(res == -1)
     printf("Error getsockopt one");
 else
     printf("rcv buffer size = %d\n", sendbuff);

 // Set buffer size
 sendbuff = 20480;

 printf("sets the rcv buffer to %d\n", sendbuff);
 res = setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &sendbuff, sizeof(sendbuff));

 if(res == -1)
     printf("Error setsockopt");


 // Get buffer size
 optlen = sizeof(sendbuff);
 res = getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &sendbuff, &optlen);

 if(res == -1)
     printf("Error getsockopt two");
 else
     printf("rcv buffer size = %d\n", sendbuff);

 return 0;
}
