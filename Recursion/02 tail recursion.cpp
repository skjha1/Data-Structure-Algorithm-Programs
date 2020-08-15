#include<stdio.h>
void func1(int n)
{
	if (n>0)
	{
		
		printf("%d ",n);
		func1(n-1);
	}
}
int main (){
	int x=9;
	func1(x);
	return 0;
}
