/* Combination nCr problem 

code By Shivendra jha 


*/

#include<stdio.h>
int fact(int n)
{
	if (n<=1)
	return 1;
	else 
	return fact(n-1)*n;
}
int nCr(int n,int r)


{
	int num,den;
	num= fact(n);
	den=fact(r)*fact(n-r);
	
	return num/den;
}
int main ()
{
	int x,y;
	printf("Enter the value of n and r  \n");
	scanf("%d%d",&x,&y);
	printf("The nCr is : %d",nCr(x,y));
}
