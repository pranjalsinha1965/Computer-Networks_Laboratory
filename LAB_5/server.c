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
    printf("socket created");
    struct sockaddr_in seraddr, cliaddr1,cliaddr2;
    int len = sizeof(seraddr);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(3490);
    seraddr.sin_addr.s_addr = INADDR_ANY;
    int bfd = bind(sfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if (bfd == -1)
    {
      printf("\nBind not found");
    }
    else
    {
      printf("\nBind Found");

      printf("\nQuestion-1\n");
      int a;
      int f = recvfrom(sfd, &a, sizeof(a), 0, (struct sockaddr *)&cliaddr1, &len);
      int b;
      int g = recvfrom(sfd, &b, sizeof(b), 0, (struct sockaddr *)&cliaddr1, &len);

      char buffer[1024];
      int nc;
      nc = recvfrom(sfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr2, &len);

      int result1, result2, result3, result4;
      int result5;

      printf("\nAddition Performed\n", result1 = a + b);
      int s1 = sendto(sfd, (int *)&result1, sizeof(result1), 0, (struct sockaddr *)&cliaddr2, sizeof(cliaddr2));

      printf("\nSubtraction Performed%d\n", result2 = a - b);
      int s2 = sendto(sfd, (int *)&result2, sizeof(result2), 0, (struct sockaddr *)&cliaddr2, sizeof(cliaddr2));

      printf("\nMultiplication Performed%d\n", result3 = a * b);
      int s3 = sendto(sfd, (int *)&result3, sizeof(result3), 0, (struct sockaddr *)&cliaddr2, sizeof(cliaddr2));

      printf("\nDivision Performed%d\n", result4 = a / b);
      int s4 = sendto(sfd, (int *)&result4, sizeof(result4), 0, (struct sockaddr *)&cliaddr2, sizeof(cliaddr2));

      printf("\nModulo Performed%d\n", result5 = a % b);
      int s5 = sendto(sfd, (int *)&result5, sizeof(result5), 0, (struct sockaddr *)&cliaddr2, sizeof(cliaddr2));
    }
    close(sfd);
    return 0;
  }
}
