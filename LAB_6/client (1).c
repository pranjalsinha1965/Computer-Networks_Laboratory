#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
  int sfd;
  sfd = socket(AF_INET, SOCK_STREAM, 0);
  char client_message[1000], server_message[1000];

  if (sfd == -1)
  {
    printf("socket not created \n");
    exit(0);
  }
  else
  {
    printf("socket created \n");
    struct sockaddr_in seraddr, cliaddr;
    int len = sizeof(cliaddr);
    int length = sizeof(seraddr);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(2000);
    seraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    printf("Enter the Name: ");
    scanf("%s", client_message);
    send(sfd, client_message, sizeof(client_message), 0);

    int r = recv(sfd, server_message, sizeof(server_message), 0);
    printf("server_message=%s\n", server_message);
  }
  int close(int sfd);

  return 0;
}