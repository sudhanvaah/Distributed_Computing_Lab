#include <sys/socket.h>
#include <stdio.h>

struct ling {
  int l_onoff;
  int l_linger;
} linger;

int main(int argc, char **argv)
{
 int sockfd;
 socklen_t optlen;

 sockfd = socket(AF_INET, SOCK_DGRAM, 0);
 if(sockfd == -1)
     printf("Error");

 int res = 0;


 optlen = sizeof(linger);
 res = getsockopt(sockfd, SOL_SOCKET, SO_LINGER, &linger, &optlen);

 if(res == -1)
     printf("Error getsockopt one");
 else
      printf("SO_Lingeris %s for %d\n", (linger.l_onoff ? "ON" : "OFF"),linger.l_linger);

 // Set KeepLIVE
 linger.l_onoff=1;
 linger.l_linger=5;

 printf("sets the linger\n");
 res = setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &linger, sizeof(linger));

 if(res == -1)
     printf("Error setsockopt");

 linger.l_onoff=0;
 linger.l_linger=0;
 // test now
 optlen = sizeof(linger);
 res = getsockopt(sockfd, SOL_SOCKET, SO_LINGER, &linger, &optlen);

 if(res == -1)
     printf("Error getsockopt two");
 else
     printf("SO_Lingeris %s for %d\n", (linger.l_onoff ? "ON" : "OFF"),linger.l_linger);

 return 0;
}
