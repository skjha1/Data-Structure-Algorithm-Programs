#include<stdio.h>
int TOH (int n,int A, int B , int C)
{
	if (n>0)
	{
		TOH (n-1,A,C,B);
		printf("(%d,%d) \n",A,C);  // This gives the total no of steps we get 
		TOH(n-1,B,A,C);
	}
	return 0;
}
int main()
{
	int p,a,b,c;
	printf("Enter the no of disk and the number of tower ");
	scanf("%d %d %d %d",&p,&a,&b,&c); // Here p is no of disk & a,b,c are no of tower 
	printf("finaally we get all the disk at tower 1 is  %d \n",TOH(p,a,b,c));
	return 0;
}
