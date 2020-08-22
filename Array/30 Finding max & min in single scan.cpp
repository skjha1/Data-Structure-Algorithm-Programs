#include<iostream>
using namespace std;
int main()
{
	int A[10]={5,8,3,9,6,2,10,7,-1,4};
	int n=sizeof(A)/sizeof(int);
	int max=A[0];
	int min=A[0];
	for (int i=0;i<n;i++)
	{
		if (A[i]<min)
		min=A[i];
		else if (A[i]>max)
		max=A[i];
	}
	cout<<"Maximun is "<<max<<endl<<"Minimum is "<<min <<endl;
	return 0;
}
