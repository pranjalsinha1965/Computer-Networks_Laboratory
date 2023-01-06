#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int sfd;
  sfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sfd == -1)
  {
    printf("Socket not found\n");
    exit(0);
  }
  else
  {
    printf("Socket created");
    struct sockaddr_in seraddr, cliaddr2;
    int len = sizeof(seraddr);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(3490);
    seraddr.sin_addr.s_addr = INADDR_ANY;
    cliaddr2.sin_family = AF_INET;
    cliaddr2.sin_addr.s_addr = INADDR_ANY;

    char ms[] = "Hello from Client2";
    int ss;
    ss = sendto(sfd, ms, strlen(ms), 0, (struct sockaddr *)&seraddr, len);

    int res1;
    int r1 = recvfrom(sfd, (int *)&res1, sizeof(res1), 0, (struct sockaddr *)&seraddr, &len);

    int res2;
    int r2 = recvfrom(sfd, (int *)&res2, sizeof(res2), 0, (struct sockaddr *)&seraddr, &len);

    int res3;
    int r3 = recvfrom(sfd, (int *)&res3, sizeof(res3), 0, (struct sockaddr *)&seraddr, &len);

    int res4;
    int r4 = recvfrom(sfd, (int *)&res4, sizeof(res4), 0, (struct sockaddr *)&seraddr, &len);

    int res5;
    int r5 = recvfrom(sfd, (int *)&res5, sizeof(res5), 0, (struct sockaddr *)&seraddr, &len);

    printf("Addition Result: %d\n", res1);
    printf("Subtraction Result: %d\n", res2);
    printf("Multification Result: %d\n", res3);
    printf("Division Result: %d\n", res4);
    printf("Modulo Result: %d\n", res5);
  }
  close(sfd);
  return 0;
}