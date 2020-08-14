/* Factorial of a numbet using recursion 

code by shivendra k jha 

*/

# include <stdio.h>
int fact(int n)
{
	if (n==0)
	return 1;
	else 
	return fact(n-1)*n;
}
int main ()
{
	int x;
	printf("Enter a number ");
	scanf("%d",&x);
	int a=fact(x);
	printf("The factorail of given number is %d : ",a);
	
	return 0;
}
