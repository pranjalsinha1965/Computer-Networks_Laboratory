#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
  char client_message[1000], server_message[1000] = "2029152";
  int sfd, client_sock;
  sfd = socket(AF_INET, SOCK_STREAM, 0);
  
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
    int bfd = bind(sfd, (const struct sockaddr *)&seraddr, length);
    if (bfd == -1)
    {
      printf("bind error\n");
      exit(0);
    }
    else
    {
      printf("bind successful \n");
      listen(sfd, 1);
      client_sock = accept(sfd, (struct sockaddr *)&cliaddr, &len);
    }

    int r = recv(client_sock, client_message, sizeof(client_message), 0);
    printf("client_message=%s\n", client_message);

    send(client_sock, server_message, sizeof(server_message), 0);
  }
  int close(int client_sock);
  int close(int sfd);

  return 0;
}
