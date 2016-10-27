#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<time.h>
#include<sys/time.h>
void main()
{
	int sfd;
	char buf[50];
	struct sockaddr_in sa;
	struct timeval stop,start;
	gettimeofday(&start,NULL);
	sa.sin_family=AF_INET;
	sa.sin_port=htons(12000);
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	connect(sfd,(struct sockaddr *)&sa,sizeof(sa));
	recv(sfd,buf,sizeof(buf),0);
	printf("Transaction time of client-server :");
	fputs(buf,stdout);
	gettimeofday(&stop,NULL);
	printf("Round-trip time is %lu micro seconds\n",stop.tv_usec-start.tv_usec);
}
