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

      printf("\nQuestion-1\n");
      float a;
      int f = recvfrom(sfd, &a, sizeof(a), 0, (struct sockaddr *)&cliaddr, &len);
      float b;
      int g = recvfrom(sfd, &b, sizeof(b), 0, (struct sockaddr *)&cliaddr, &len);
      char op;
      int h = recvfrom(sfd, &op, sizeof(op), 0, (struct sockaddr *)&cliaddr, &len);
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

      int s = sendto(sfd, (float *)&result, sizeof(result), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));

      printf("\nQuestion-2\n");

      // recive array of int
      int n;
      int n1 = recvfrom(sfd, &n, sizeof(n), 0, (struct sockaddr *)&cliaddr, &len);
      int arr[n];
      int r = recvfrom(sfd, arr, sizeof(arr), 0, (struct sockaddr *)&cliaddr, &len);
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

      int s1 = sendto(sfd, (int *)&count, sizeof(count), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
      int s2 = sendto(sfd, (int *)&arr1, sizeof(arr1), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));

      printf("\nQuestion-3\n");

      int rn1, rn2, rn3, rn4, rn5;
      char name1[20], name2[20], name3[20], name4[20], name5[20];
      int m1[5], m2[5], m3[5], m4[5], m5[5];

      printf("Student 1:\n");
      int r1 = recvfrom(sfd, &rn1, sizeof(rn1), 0, (struct sockaddr *)&cliaddr, &len);
      int r2 = recvfrom(sfd, name1, sizeof(name1), 0, (struct sockaddr *)&cliaddr, &len);
      int r3 = recvfrom(sfd, m1, sizeof(m1), 0, (struct sockaddr *)&cliaddr, &len);
      printf("\nMarks of %s are: ", name1);
      for (int i = 0; i < 5; i++)
      {
        printf("%d ", m1[i]);
      }
      printf("\n");
      printf("\nStudent 2:\n");
      int r4 = recvfrom(sfd, &rn2, sizeof(rn2), 0, (struct sockaddr *)&cliaddr, &len);
      int r5 = recvfrom(sfd, name2, sizeof(name2), 0, (struct sockaddr *)&cliaddr, &len);
      int r6 = recvfrom(sfd, m2, sizeof(m2), 0, (struct sockaddr *)&cliaddr, &len);
      printf("\nMarks of %s are: ", name2);
      for (int i = 0; i < 5; i++)
      {
        printf("%d ", m2[i]);
      }
      printf("\n");
      printf("\nStudent 3:\n");
      int r7 = recvfrom(sfd, &rn3, sizeof(rn3), 0, (struct sockaddr *)&cliaddr, &len);
      int r8 = recvfrom(sfd, name3, sizeof(name3), 0, (struct sockaddr *)&cliaddr, &len);
      int r9 = recvfrom(sfd, m3, sizeof(m3), 0, (struct sockaddr *)&cliaddr, &len);
      printf("\nMarks of %s are: ", name3);
      for (int i = 0; i < 5; i++)
      {
        printf("%d ", m3[i]);
      }
      printf("\n");
      printf("\nStudent 4:\n");
      int r10 = recvfrom(sfd, &rn4, sizeof(rn4), 0, (struct sockaddr *)&cliaddr, &len);
      int r11 = recvfrom(sfd, name4, sizeof(name4), 0, (struct sockaddr *)&cliaddr, &len);
      int r12 = recvfrom(sfd, m4, sizeof(m4), 0, (struct sockaddr *)&cliaddr, &len);
      printf("\nMarks of %s are: ", name4);
      for (int i = 0; i < 5; i++)
      {
        printf("%d ", m4[i]);
      }
      printf("\n");
      printf("\nStudent 5:\n");
      int r13 = recvfrom(sfd, &rn5, sizeof(rn5), 0, (struct sockaddr *)&cliaddr, &len);
      int r14 = recvfrom(sfd, name5, sizeof(name5), 0, (struct sockaddr *)&cliaddr, &len);
      int r15 = recvfrom(sfd, m5, sizeof(m5), 0, (struct sockaddr *)&cliaddr, &len);
      printf("\nMarks of %s are: ", name5);
      for (int i = 0; i < 5; i++)
      {
        printf("%d ", m5[i]);
      }
      printf("\n");
      // find highest marks
      int max1 = 0, max2 = 0, max3 = 0, max4 = 0, max5 = 0;
      for (int i = 0; i < 5; i++)
      {
        max1 += m1[i];
        max2 += m2[i];
        max3 += m3[i];
        max4 += m4[i];
        max5 += m5[i];
      }

      if (max1 > max2 && max1 > max3 && max1 > max4 && max1 > max5)
      {
        int s3 = sendto(sfd, (int *)&rn1, sizeof(rn1), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s4 = sendto(sfd, name1, sizeof(name1), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s5 = sendto(sfd, (int *)&max1, sizeof(max1), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
      }

      else if (max2 > max3 && max2 > max4 && max2 > max5)
      {
        int s6 = sendto(sfd, (int *)&rn2, sizeof(rn2), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s7 = sendto(sfd, name2, sizeof(name2), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s8 = sendto(sfd, (int *)&max2, sizeof(max2), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
      }

      else if (max3 > max4 && max3 > max5)
      {
        int s9 = sendto(sfd, (int *)&rn3, sizeof(rn3), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s10 = sendto(sfd, name3, sizeof(name3), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s11 = sendto(sfd, (int *)&max3, sizeof(max3), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
      }

      else if (max4 > max5)
      {
        int s12 = sendto(sfd, (int *)&rn4, sizeof(rn4), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s13 = sendto(sfd, name4, sizeof(name4), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s14 = sendto(sfd, (int *)&max4, sizeof(max4), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
      }

      else
      {
        int s15 = sendto(sfd, (int *)&rn5, sizeof(rn5), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s16 = sendto(sfd, name5, sizeof(name5), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        int s17 = sendto(sfd, (int *)&max5, sizeof(max5), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
      }
    }
  }
  close(sfd);
  return 0;
}