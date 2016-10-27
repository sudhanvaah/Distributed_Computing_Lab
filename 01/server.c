#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
void main()
{
	int sfd,len,afd,pid;
	char buf[50],buf1[50];
	struct sockaddr_in sa,ca;
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=htons(18000);
	sfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bind(sfd,(struct sockaddr *)&sa,sizeof(sa));
	listen(sfd,4);
	while(1)
	{
		len=sizeof(ca);
		afd=accept(sfd,(struct sockaddr *)&ca,&len);
		printf("Connected to client with id %d\n",afd);
		if((pid=fork())==0)
		{
			recv(afd,buf,50,0);
			fputs(buf,stdout);
			printf("Enter reply to client\n");
			fgets(buf1,50,stdin);
			send(afd,buf1,sizeof(buf1),0);
			close(afd);
		}
	}
	close(sfd);
}
