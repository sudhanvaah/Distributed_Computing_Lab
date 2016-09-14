#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
void str_echo(int s)
{
char buf[50],buf1[50];
puts("Enter the Message...");
fgets(buf,50,stdin);
send(s,buf,50,0); //sending data to server
//receiving data from server
recv(s,buf1,50,0);
puts("Message from Server...");
fputs(buf1,stdout);
}
int main()
{
int ls;
struct sockaddr_in cli;
puts("I am Client...");
/*creating socket*/
ls=socket(AF_INET,SOCK_STREAM,0);
puts("Socket Created Successfully...");
/*socket address structure*/
cli.sin_family=AF_INET;
cli.sin_addr.s_addr=inet_addr("127.0.0.1");
cli.sin_port=htons(5000);
/*connecting to server*/
connect(ls,(struct sockaddr*)&cli,sizeof(cli));
puts("Connected with Server...");
str_echo(ls);
close(ls);
return 0;
}
