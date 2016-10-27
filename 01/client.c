#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
void main()
{
	int sfd;
	char buf[50],buf1[50];
	struct sockaddr_in sa;
	sa.sin_family=AF_INET;
	sa.sin_port=htons(18000);
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	connect(sfd,(struct sockaddr *)&sa,sizeof(sa));
	puts("Enter data to send to client");
	fgets(buf,50,stdin);
	send(sfd,buf,sizeof(buf),0);
	recv(sfd,buf1,sizeof(buf1),0);
	fputs(buf1,stdout);
	close(sfd);
}
