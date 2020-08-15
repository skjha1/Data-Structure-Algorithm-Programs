#include<stdio.h>
int fib(int n)
{
	int t0=0,t1=1,sum=0,i;
	if (n<=1) return n;
	for (i=2;i<=n;i++)
	{
		sum=t0+t1;
		t0=t1;
		t1=sum;
	}
	return sum;
}

int rfib(int n )
{
	if (n<=1)
	return n;
	else 
	return rfib(n-2)+rfib(n-1);
}
int  main ()
{
	int a ;
	printf("Enter a number ");
	scanf("%d",&a);
	printf("fibbo using recursive function %d \n",rfib(a)); // time complexity for this is 2 pow n
	printf("fibbo using loop is %d \n",fib(a)); // time complexity for this is o(n)
	return 0;
}
