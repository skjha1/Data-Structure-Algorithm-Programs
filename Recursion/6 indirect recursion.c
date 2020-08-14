#include<stdio.h>
int fun(int n)
{
	if (n>100)
	return n-10;
	else
	return fun(fun(n+11));
}
int main ()
{
	int r;
	r=fun(800); // for any value more than 100 it will print ( value - 10 )
	printf("%d\n",r); // for any value less then 100 or equal to 100 it will return 91 
	return 0;
}
