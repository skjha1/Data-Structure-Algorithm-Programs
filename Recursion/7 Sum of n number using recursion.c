/* 
Q- The Sum of 1st n terms 


Code by Shivendra K JHa
*/
#include<stdio.h>
int sum (int n)
{
	if (n>0)
	return sum(n-1)+n;
	else 
	return 0;
}
int main ()
{
	int a;
	printf("Enter a number  ");
	scanf("%d",&a);
	printf("The sum upto that number : %d",sum(a));
	return 0;
}
