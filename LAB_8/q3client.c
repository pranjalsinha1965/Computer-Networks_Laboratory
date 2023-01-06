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
char name[25];
};
int main()
{
int i,sockfd,r1;
char buf[100];
struct student s1[5],hs;
struct sockaddr_in sa;
sockfd=socket(AF_INET,SOCK_STREAM,0);
sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=60018;
i= connect(sockfd,(struct sockaddr   *)&sa,sizeof(sa));
for(int j=0;j<5;j++)
{
printf("Enter a rollno=");
scanf("%d",&s1[i].roll);
printf("Enter the name = ");
scanf("%s",s1[i].name);
printf("Enter marks =");
scanf("%f",&s1[i].m1);
}
send(sockfd,&s1,sizeof(s1),0);
recv(sockfd,&hs,sizeof(hs),0);
printf("The student with max marks\n");
printf("Roll : %d\n",hs.roll);
printf("Name : %s",hs.name);
printf("Marks : %f", hs.m1);
close(sockfd);
return 0;
}