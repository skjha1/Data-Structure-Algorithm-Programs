#include<stdio.h>
#include<stdlib.h>
int main ()
{
	int A[5]={2,3,4,6,7};  // this will allocate memory in stack memory 
	int *p;
	int i;
	
	p= (int *)malloc(5*sizeof(int)); // using malloc we can access memory in heap 
	p[0]=8;
	p[1]=7;
	p[2]=9;
	p[3]=10;
	p[4]=12;
	
	for (i=0;i<5;i++)
	{
		printf("%d ",A[i]);
		
	}
	printf("\n");
	for (i=0;i<5;i++)
	{
		printf("%d ",p[i]);
		
	}
	return 0;
}
