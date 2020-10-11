#include<stdio.h>
void func1(int n)
{
	if (n>0) // Base condition
	{
		func1(n-1); // 1st call then print 
		printf("%d ",n);
	}
}
int main (){
	int x=9;
	func1(x); // passing parameter to fxn 
	return 0;
}
