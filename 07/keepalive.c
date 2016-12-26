#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char **argv)
{
 int sockfd, optval;
 socklen_t optlen;

 sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 if(sockfd == -1)
     printf("Error");

 int res = 0;


 optlen = sizeof(optval);
 res = getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen);

 if(res == -1)
     printf("Error getsockopt one");
 else
      printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));

 // Set KeepLIVE
 optval=1;

 printf("sets the keepalive\n");
 res = setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(optval));

 if(res == -1)
     printf("Error setsockopt");


 // test now
optval=0;
 optlen = sizeof(optval);
 res = getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen);

 if(res == -1)
     printf("Error getsockopt two");
 else
     printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));

 return 0;
}
