/* Power Using Recursion 

code by shivendra k jha 

*/

#include<stdio.h>
#include<math.h>
int power(m,n)
{
	if (m==0)
	return 1;
	else 
	return pow(m,n-1)*m;
	
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
