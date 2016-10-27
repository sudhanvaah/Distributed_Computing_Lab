#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<time.h>
void main()
{
	int sfd,len,pid;
	char buf[50];
	struct sockaddr_in sa,ca;
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=htons(15000);
	sfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	bind(sfd,(struct sockaddr *)&sa,sizeof(sa));
	while(1)
	{
		len=sizeof(ca);
		recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&ca,&len);
		puts("Client accepted");
		if((pid=fork())==0)
		{
			printf("Message from client\n");
			puts(buf);
			printf("Enter reply to send\n");
			fgets(buf,50,stdin);
			sendto(sfd,buf,sizeof(buf),0,(struct sockaddr *)&ca,len);
		}
	}
	close(sfd);
}
