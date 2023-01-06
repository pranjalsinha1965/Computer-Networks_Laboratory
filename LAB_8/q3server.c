#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<string.h>
struct student{
int roll;
float m1;
char name[100];
};
int main()
{
int length,sockfd,fd1,r1,i,max;
struct sockaddr_in sa,ta1;
struct student s1[5],hs;
sockfd=socket(AF_INET,SOCK_STREAM,0);
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=INADDR_ANY;
sa.sin_port=60018;
i=bind(sockfd,(struct sockaddr *)&sa, sizeof(sa));
printf("Test %d%d\n", sockfd,i);
listen(sockfd,5);
length=sizeof(sa);
fd1=accept(sockfd,(struct sockaddr *)&ta1,&length);
recv(fd1,&s1,sizeof(s1),0);
max=s1[0].m1;
for( int k=1;k<5;k++){
if(max<s1[k].m1)
max=s1[k].m1;
}
for(int k=0; k<5; k++)
{
if(s1[k].m1==max)
{
hs.roll=s1[k].roll;
strcpy(hs.name,s1[k].name);
hs.m1=s1[k].m1;
}}
send(fd1,&hs,sizeof(hs),0);
close(fd1);
return 0;
}