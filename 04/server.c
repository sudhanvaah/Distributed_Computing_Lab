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
	int sfd,afd,len;
	time_t t;
	char buf[200];
	struct sockaddr_in sa,ca;
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=htons(12000);
	sfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bind(sfd,(struct sockaddr *)&sa,sizeof(sa));
	listen(sfd,3);
	printf("Listening . . .\n");
	len=sizeof(ca);
	afd=accept(sfd,(struct sockaddr *)&ca,&len);
	printf("Connected to client with id %d\n",afd);
	t=time(NULL);
	snprintf(buf,sizeof(buf),"%.24s\n",ctime(&t));
	send(afd,buf,sizeof(buf),0);
	close(afd);
	close(sfd);
}
	
