#include<iostream>
using namespace std ;
int main ()
{
	int i,j;
	int  A[10]={2,3,1,8,6,7,9,1,5,4};
	int k=10;
	int n=sizeof(A)/sizeof(int);
	
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (A[i]+A[j]==k)
			cout <<A[i]<<"+"<<A[j]<<"="<<k<<endl;
		}
	}
	return 0;
}
// time complexity is o(n^2)
