#include<stdio.h>
void tail(int n)
{
	if (n > 0)
	{
		printf("%d ", n);
		tail(n-1);
	}
}
int main()
{
	int a;
	scanf_s("%d", &a);
	tail(a);
	return 0; 
}