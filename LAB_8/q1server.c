#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<string.h>
struct calcul{
float a,b,res;
char x[2];
};
int main()
{
int length,sockfd,fd1,r1,i,max;
struct sockaddr_in sa,ta1;
struct calcul s1,hs;
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
switch(s1.x[0])  
    {  
        case '+':  
            hs.res = s1.a + s1.b; // add two numbers  
           
            break;  
          
        case '-':  
            hs.res = s1.a - s1.b; // subtract two numbers  
            
            break;  
              
        case '*':  
            hs.res = s1.a * s1.b; // multiply two numbers  
            
            break;            
          
        case '/':  
            
            hs.res = s1.a / s1.b; // divide two numbers  
              
            break;  
        default: 
            printf (" Something is wrong!!  ");               
    }
send(fd1,&hs,sizeof(hs),0);
close(fd1);
return 0;
}