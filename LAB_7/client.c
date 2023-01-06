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
  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd == -1)
  {
    printf("Socket not found\n");
    exit(0);
  }
  else
  {
    printf("Socket created");
    struct sockaddr_in seraddr, cliaddr;
    int len = sizeof(seraddr);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(3490);
    seraddr.sin_addr.s_addr = INADDR_ANY;
    connect(sfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

    float a;
    printf("\nEnter a number: ");
    scanf("%f", &a);
    int f = send(sfd, (float *)&a, sizeof(a), 0);

    float b;
    printf("Enter a number: ");
    scanf("%f", &b);
    int g = send(sfd, (float *)&b, sizeof(b), 0);

    char op;
    printf("Enter a operator: ");
    scanf(" %c", &op);
    int h = send(sfd, (char *)&op, sizeof(op), 0);

    float res;
    int r = recv(sfd, (float *)&res, sizeof(res), 0);

    printf("Result: %f\n", res);

    printf("\nQuestion-2\n");

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &arr[i]);
    }
    int m = send(sfd, (int *)&n, sizeof(n), 0);
    int k = send(sfd, (int *)&arr, sizeof(arr), 0);
    // receive array of result from server
    int count;
    int c = recv(sfd, (int *)&count, sizeof(count), 0);
    int arr1[count];
    int l = recv(sfd, (int *)&arr1, sizeof(arr1), 0);
    printf("Result: ");
    for (int i = 0; i < count; i++)
    {
      printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("\nQuestion-3\n");

    // Define a structure of student
    struct student
    {
      char name[20];
      int roll;
      int marks[5];
    };
    struct student ar[5], rcc;
    printf("Enter details of 5 students: ");
    for (int i = 0; i < 5; i++)
    {
      printf("Enter name: ");
      scanf("%s", ar[i].name);
      printf("Enter roll: ");
      scanf("%d", &ar[i].roll);
      printf("Enter marks: ");
      for (int j = 0; j < 5; j++)
      {
        scanf("%d", &ar[i].marks[j]);
      }
    }
    int p = send(sfd, (struct student *)&ar, sizeof(ar), 0);
    // recive struct from server
    int ncc = recv(sfd, (struct student *)&rcc, sizeof(rcc), 0);
    printf("Result: ");
    // print struct details
    printf("\nName: %s", rcc.name);
    printf("\nRoll: %d", rcc.roll);
    printf("\nMarks: ");
    for (int i = 0; i < 5; i++)
    {
      printf("%d ", rcc.marks[i]);
    }
    printf("\n");
  }

  close(sfd);
  return 0;
}