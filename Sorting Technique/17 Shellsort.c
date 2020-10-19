Shell Sort
#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}
void ShellSort(int A[],int n)
{
 int gap,i,j,temp;

 for(gap=n/2;gap>=1;gap/=2)
 {
 for(i=gap;i<n;i++)
 {
 temp=A[i];
 j=i-gap;
 while(j>=0 && A[j]>temp)
 {
 A[j+gap]=A[j];
 j=j-gap;
 }
 A[j+gap]=temp;

 }
 }

}
int main()
{
 int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;

 SellSort(A,n);

 for(i=0;i<10;i++)
 printf("%d ",A[i]);
 printf("\n");

 return 0;
}