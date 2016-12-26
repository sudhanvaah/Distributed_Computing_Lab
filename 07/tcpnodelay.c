#include <sys/socket.h>
#include <stdio.h>
#include <netinet/tcp.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
 int sockfd;
 int flag;
 socklen_t optlen;

 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 if(sockfd == -1)
     printf("Error");

 int res = 0;


 optlen = sizeof(int);
 res = getsockopt(sockfd,IPPROTO_TCP,TCP_NODELAY,(char *)&flag,&optlen);

 if(res == -1)
     printf("Error getsockopt one\n");
 else
      printf("Nagle's algo is %s\n", (flag? "ON" : "OFF"));

 // Set Nagle's
 flag=1;
 printf("sets the tcp_nodelay\n");
 res = setsockopt(sockfd,IPPROTO_TCP,TCP_NODELAY,(char *)&flag,sizeof(int));

 if(res == -1)
     printf("Error setsockopt\n");


 // test now
flag=0;
 optlen = sizeof(flag);
 res = getsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY,(char *)&flag, &optlen);

 if(res == -1)
     printf("Error getsockopt two\n");
 else
     printf("Nagle's algo is %s\n", (flag ? "ON" : "OFF"));

 return 0;
}
