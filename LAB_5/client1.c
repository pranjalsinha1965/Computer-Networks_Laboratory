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
    struct sockaddr_in seraddr, cliaddr1;
    int len = sizeof(seraddr);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(3490);
    seraddr.sin_addr.s_addr = INADDR_ANY;
    cliaddr1.sin_family = AF_INET;
    cliaddr1.sin_addr.s_addr = INADDR_ANY;

    int a;
    printf("\nEnter a number: ");
    scanf("%d", &a);
    int f = sendto(sfd, (int *)&a, sizeof(a), 0, (struct sockaddr *)&seraddr, len);

    int b;
    printf("Enter a number: ");
    scanf("%d", &b);
    int g = sendto(sfd, (int *)&b, sizeof(b), 0, (struct sockaddr *)&seraddr, len);
  }
  close(sfd);
  return 0;
}
