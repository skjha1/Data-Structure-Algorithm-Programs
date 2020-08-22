#include<iostream>
using namespace std;
int main ()
{
	int A[10]={3,6,8,8,10,12,15,15,15,20};
	int lastduplicate=0;
	int i,no=10;
	
	cout<<"Duplicate Elements are "<<endl;
	for (i=0;i<no;i++)
	{
		if (A[i]==A[i+1] && A[i]!=lastduplicate)
		{
			cout<<" "<<A[i];
			lastduplicate=A[i];
		}
	}
	return 0;
	
}
