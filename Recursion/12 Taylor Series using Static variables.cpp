/* Power Using Recursion 

code by shivendra k jha 

*/

#include<stdio.h>
int e(int x, int n)
{
	static double p=1,f=1;
	int r;
	if (n==0)
	return 1;
	else 
	{
		r=e(x,n-1);
		p=p*x;
		f=f*n;
		return r+p/f;
	}
	
}
int main ()
{
	int a,b;
	printf("Enter the numbers to be operated ");
	scanf("%d%d",&a,&b);
	int c=e(a,b);
	printf("taylor seris of e pow x is %d ",c);
	return 0;
}
