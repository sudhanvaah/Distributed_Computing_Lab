#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char **argv)
{
 int sockfd, optval;
 socklen_t optlen;

 sockfd = socket(AF_INET, SOCK_DGRAM, 0);

 int res = 0;


 optlen = sizeof(optval);
 res = getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen);
      printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));

 // Set KeepLIVE
 optval=1;

 printf("sets the keepalive\n");
 res = setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(optval));


 // test now
 optlen = sizeof(optval);
 res = getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, &optlen);

     printf("SO_KEEPALIVE is %s\n", (optval ? "ON" : "OFF"));

 return 0;
}
