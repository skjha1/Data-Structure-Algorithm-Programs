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
int F[10];
int mfib(int n)
{
	if (n<=1)
	{
		F[n]=n;  // in function F of n simply return the value of the n if n is less then 1;
		return n;
	}
	else 
	{
		if (F[n-2]==-1) // if place is not called then
		F[n-2]=mfib(n-2); // call recursively
		if (F[n-1]==-1); // if this is also not called then
		F[n-1]=mfib(n-1);// call recursively
		
		return F[n-2]+F[n-1]; // at last return the sum of the called terms 
	}
	
}

int  main ()
{
	int a,i ;
	for (i=0;i<=10;i++)
	F[i]=F[i]-1;
	printf("Enter a number ");
	scanf("%d",&a);
	printf("fibbo using recursive function %d \n",rfib(a)); // time complexity for this is 2 pow n
	printf("fibbo using loop is %d \n",fib(a)); // time complexity for this is o(n)
	printf("Fibbo using memoization is %d ",mfib(a)); // Time complexity using memoization is o(n) where space is takes very less , it works on dynamic programmin 
	return 0;
}
