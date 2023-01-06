#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

struct student
{
  char name[20];
  int roll;
  int marks[5];
};

int main()
{

  int sfd;
  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd == -1)
  {
    printf("Socket not found\n");
    exit(0);
  }
  else
  {
    printf("socket created");
    struct sockaddr_in seraddr, cliaddr;
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
      listen(sfd, 1);
      int client_sock = accept(sfd, (struct sockaddr *)&cliaddr, &len);

      printf("\nQuestion-1\n");
      float a;
      int f = recv(client_sock, &a, sizeof(a), 0);
      float b;
      int g = recv(client_sock, &b, sizeof(b), 0);
      char op;
      int h = recv(client_sock, &op, sizeof(op), 0);
      float result;
      switch (op)
      {
      case '+':
        printf("\nAddition is %f\n", result = a + b);
        break;
      case '-':
        printf("\nSubtraction is %f\n", result = a - b);
        break;
      case '*':
        printf("\nMultiplication is %f\n", result = a * b);
        break;
      case '/':
        printf("\nDivision is %f\n", result = a / b);
        break;
      default:
        printf("\nInvalid Operation\n");
      }

      int s = send(client_sock, (float *)&result, sizeof(result), 0);

      printf("\nQuestion-2\n");

      // recive array of int
      int n;
      int n1 = recv(client_sock, &n, sizeof(n), 0);
      int arr[n];
      int r = recv(client_sock, arr, sizeof(arr), 0);
      printf("\nArray is: ");
      for (int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
      printf("\n");
      // check for old number in array
      int arr1[n];
      int j = 0;
      int count = 0;
      for (int i = 0; i < n; i++)
      {
        if (arr[i] % 2 != 0)
        {
          count++;
          arr1[j] = arr[i];
          j++;
        }
      }

      int s1 = send(client_sock, (int *)&count, sizeof(count), 0);
      int s2 = send(client_sock, (int *)&arr1, sizeof(arr1), 0);

      printf("\nQuestion-3\n");

      // recive student struct from client
      struct student ass[5];
      int total[5];
      // recive struct from client
      int rss = recv(client_sock, ass, sizeof(ass), 0);
      for (int i = 0; i < 5; i++)
      {
        // calculate total marks
        total[i] = 0;
        for (int j = 0; j < 5; j++)
        {
          total[i] += ass[i].marks[j];
        }
      }
      // find highest total marks
      int max = total[0];
      int index = 0;
      for (int i = 0; i < 5; i++)
      {
        if (total[i] > max)
        {
          max = total[i];
          index = i;
        }
      }
      // send highest total marks to client
      int s3 = send(client_sock, &ass[index], sizeof(ass[index]), 0);
    }
  }
  close(sfd);
  return 0;
}