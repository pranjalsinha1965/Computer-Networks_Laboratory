#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<string.h>
struct student{
int num;
};
int main()
{
int i,sockfd,r1;
char buf[100];
int n;
printf("The number of integer to be add");
scanf("%d",&n);
struct student s1[n];
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_STREAM,0);
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=60018;
i= connect(sockfd,(struct sockaddr   *)&sa,sizeof(sa));
for(int j=0;j<n;j++)
{
printf("Enter a no=");
scanf("%d",&s1[j].num);

}
int n1;
send(sockfd,&n,sizeof(n),0);
send(sockfd,&s1,sizeof(s1),0);
recv(sockfd,&n1,sizeof(n1),0);

struct student hs[n1];
recv(sockfd,&hs,sizeof(hs),0);
printf("The odd num are :\n");
for(int j=0;j<n1;j++)
{

printf("%d ",hs[j].num);

}
close(sockfd);
return 0;
}