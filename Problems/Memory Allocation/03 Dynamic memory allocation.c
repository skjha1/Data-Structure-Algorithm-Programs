/*Write a program to find sum of n elements entered by user. To perform this program, allocate memory dynamically using malloc() function
TEST CASE 1

INPUT
5
1 2 3 4 5
OUTPUT
Sum=15
TEST CASE 2

INPUT
7
5 5 5 5 5 1 1
OUTPUT
Sum=27
*/
#include<stdio.h>
#include<stdlib.h>
int main ()
{
  int i,no,*p,sum=0;
  scanf("%d",&no);
  p= (int * ) malloc (no*sizeof(int));

  for (i=0;i<=no;i++)
  {
    scanf("%d",p+i);
  }
  for(i=0;i<no;i++){
  sum=sum+*p;
    p++;
}
printf("Sum=%d",sum);
return 0;
}