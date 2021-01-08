/*
Sample input:
4
1
2
5
3
Sample output:

1
2
120
6
*/

// by shivendra
#include <iostream>
using namespace std;

int fact(int n)
{
    if (n<=1)
    return 1;
    else
    return n*fact(n-1);
}

int main() {
	int t;
	cin>>t;
	while (t--)
	{
	    int a;
	    cin>>a;
	    cout<<fact(a)<<endl;
	}
	return 0;
}
