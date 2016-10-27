#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
void main()
{
	int sfd,len;
	char buf[50],buf1[50];
	struct sockaddr_in sa;
	sa.sin_family=AF_INET;
	sa.sin_addr.s_addr=inet_addr("127.0.0.1");
	sa.sin_port=htons(15000);
	sfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	printf("Enter some data to send to server\n");
	fgets(buf,sizeof(buf),stdin);
	sendto(sfd,buf,sizeof(buf),0,(struct addr *)&sa,sizeof(sa));
	len=sizeof(sa);
	recvfrom(sfd,buf1,sizeof(buf1),0,(struct addr *)&sa,&len);
	puts(buf1);
	close(sfd);
}
