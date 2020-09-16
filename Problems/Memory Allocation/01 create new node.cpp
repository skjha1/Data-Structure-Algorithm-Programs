/*
Your job is to create number of nodes as per user request using pointer
4
1 4 5 99
1 4 5 99
5
1 4 5 99 100
1 4 5 99 100
2
1 4
1 4

*/
#include<stdio.h>
#include<stdlib.h>
int main ()
{
  int *p,i,no;
  scanf("%d",&no);
  p = (int *)malloc (no*sizeof(int));
  for (i=0;i<no;i++)
    scanf("%d",p+i);
  for (i=0;i<no;i++)
  {
    printf("%d ",*p);
    p++;
  }
  return 0;
}