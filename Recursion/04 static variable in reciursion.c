#include<stdio.h>
int func(int n)
{
	static int x=0;
	if (n>0){
	x++;
	return (func(n-1))+x;
} 
return 0;

}
int main ()
{
	int a=5;
	a=func(5);
	printf("%d\n",a);
	
	a=func(5);
	printf("%d",a);
}
