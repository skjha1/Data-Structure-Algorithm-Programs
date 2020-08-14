/* Power Using Recursion 

code by shivendra k jha 

*/

#include<stdio.h>
#include<math.h>
int power(int m,int n)
{
	if (n==0)
	return 1;
	if (n%2==0)
	return pow(m*m,n/2);
	else 
	return m*pow(m*m,(n-1)/2);
	
}
int main ()
{
	int a,b;
	printf("enter the numbers ");
	scanf("%d %d",&a,&b);
	int c=power(a,b);
	printf("%d",c);
	return 0;
	
}
