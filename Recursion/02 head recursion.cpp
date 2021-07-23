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

// This will give output as 1 2 3 4 5 6 7 8 9 


#include<iostream>
using namespace std;

void func(int n)
{
    if (n>0)
    {
        func(n-1);
        cout<< n<<" ";
    }
}



int main ()
{
    int a;
    cin>>a;
    func(a);
    return 0;
}
