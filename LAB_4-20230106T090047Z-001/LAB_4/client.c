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
    struct sockaddr_in seraddr, cliaddr;
    int len = sizeof(seraddr);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(3490);
    seraddr.sin_addr.s_addr = INADDR_ANY;
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_addr.s_addr = INADDR_ANY;
    int bfd = bind(sfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    if (bfd == -1)
    {
      printf("\nBind not found");
    }
    else
    {
      printf("\nBind Found");
      float a;
      printf("\nEnter a number: ");
      scanf("%f", &a);
      int f = sendto(sfd, (float *)&a, sizeof(a), 0, (struct sockaddr *)&seraddr, len);

      float b;
      printf("Enter a number: ");
      scanf("%f", &b);
      int g = sendto(sfd, (float *)&b, sizeof(b), 0, (struct sockaddr *)&seraddr, len);

      char op;
      printf("Enter a operator: ");
      scanf(" %c", &op);
      int h = sendto(sfd, (char *)&op, sizeof(op), 0, (struct sockaddr *)&seraddr, len);

      float res;
      int r = recvfrom(sfd, (float *)&res, sizeof(res), 0, (struct sockaddr *)&seraddr, &len);

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
      int m = sendto(sfd, (int *)&n, sizeof(n), 0, (struct sockaddr *)&seraddr, len);
      int k = sendto(sfd, (int *)&arr, sizeof(arr), 0, (struct sockaddr *)&seraddr, len);
      // receive array of result from server
      int count;
      int c = recvfrom(sfd, (int *)&count, sizeof(count), 0, (struct sockaddr *)&seraddr, &len);
      int arr1[count];
      int l = recvfrom(sfd, (int *)&arr1, sizeof(arr1), 0, (struct sockaddr *)&seraddr, &len);
      printf("Result: ");
      for (int i = 0; i < count; i++)
      {
        printf("%d ", arr1[i]);
      }
      printf("\n");

      printf("\nQuestion-3\n");

      int r1, r2, r3, r4, r5;
      int m1[5], m2[5], m3[5], m4[5], m5[5];
      printf("Student 1 Details:\n");
      printf("Enter Roll Number: ");
      scanf("%d", &r1);
      printf("Enter Name: ");
      char n1[20];
      scanf("%s", n1);
      printf("Enter Marks of 5 subjects: ");
      for (int i = 0; i < 5; i++)
      {
        scanf("%d", &m1[i]);
      }
      int s1 = sendto(sfd, (int *)&r1, sizeof(r1), 0, (struct sockaddr *)&seraddr, len);
      int s2 = sendto(sfd, (char *)&n1, sizeof(n1), 0, (struct sockaddr *)&seraddr, len);
      int s3 = sendto(sfd, (int *)&m1, sizeof(m1), 0, (struct sockaddr *)&seraddr, len);
      printf("Student 2 Details:\n");
      printf("Enter Roll Number: ");
      scanf("%d", &r2);
      printf("Enter Name: ");
      char n2[20];
      scanf("%s", n2);
      printf("Enter Marks of 5 subjects: ");
      for (int i = 0; i < 5; i++)
      {
        scanf("%d", &m2[i]);
      }
      int s4 = sendto(sfd, (int *)&r2, sizeof(r2), 0, (struct sockaddr *)&seraddr, len);
      int s5 = sendto(sfd, (char *)&n2, sizeof(n2), 0, (struct sockaddr *)&seraddr, len);
      int s6 = sendto(sfd, (int *)&m2, sizeof(m2), 0, (struct sockaddr *)&seraddr, len);
      printf("Student 3 Details:\n");
      printf("Enter Roll Number: ");
      scanf("%d", &r3);
      printf("Enter Name: ");
      char n3[20];
      scanf("%s", n3);
      printf("Enter Marks of 5 subjects: ");
      for (int i = 0; i < 5; i++)
      {
        scanf("%d", &m3[i]);
      }
      int s7 = sendto(sfd, (int *)&r3, sizeof(r3), 0, (struct sockaddr *)&seraddr, len);
      int s8 = sendto(sfd, (char *)&n3, sizeof(n3), 0, (struct sockaddr *)&seraddr, len);
      int s9 = sendto(sfd, (int *)&m3, sizeof(m3), 0, (struct sockaddr *)&seraddr, len);
      printf("Student 4 Details:\n");
      printf("Enter Roll Number: ");
      scanf("%d", &r4);
      printf("Enter Name: ");
      char n4[20];
      scanf("%s", n4);
      printf("Enter Marks of 5 subjects: ");
      for (int i = 0; i < 5; i++)
      {
        scanf("%d", &m4[i]);
      }
      int s10 = sendto(sfd, (int *)&r4, sizeof(r4), 0, (struct sockaddr *)&seraddr, len);
      int s11 = sendto(sfd, (char *)&n4, sizeof(n4), 0, (struct sockaddr *)&seraddr, len);
      int s12 = sendto(sfd, (int *)&m4, sizeof(m4), 0, (struct sockaddr *)&seraddr, len);
      printf("Student 5 Details:\n");
      printf("Enter Roll Number: ");
      scanf("%d", &r5);
      printf("Enter Name: ");
      char n5[20];
      scanf("%s", n5);
      printf("Enter Marks of 5 subjects: ");
      for (int i = 0; i < 5; i++)
      {
        scanf("%d", &m5[i]);
      }
      int s13 = sendto(sfd, (int *)&r5, sizeof(r5), 0, (struct sockaddr *)&seraddr, len);
      int s14 = sendto(sfd, (char *)&n5, sizeof(n5), 0, (struct sockaddr *)&seraddr, len);
      int s15 = sendto(sfd, (int *)&m5, sizeof(m5), 0, (struct sockaddr *)&seraddr, len);

      // receive result from server
      int rn;
      int marks;
      char name[20];
      int c1 = recvfrom(sfd, (int *)&rn, sizeof(rn), 0, (struct sockaddr *)&seraddr, &len);
      int d1 = recvfrom(sfd, (char *)&name, sizeof(name), 0, (struct sockaddr *)&seraddr, &len);
      int e1 = recvfrom(sfd, (int *)&marks, sizeof(marks), 0, (struct sockaddr *)&seraddr, &len);

      printf("\nResult:\n");
      printf("Roll Number: %d\n", rn);
      printf("Name: %s\n", name);
      printf("Total Marks: %d\n", marks);
    }
  }
  close(sfd);
  return 0;
}