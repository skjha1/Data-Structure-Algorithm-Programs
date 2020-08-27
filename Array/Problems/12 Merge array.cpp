#include<iostream>
using namespace std;
int main()
{
	int a1[100],a2[100],a3[100],index=0;
	int n1,n2,m,i;
	cout<<"enter the number of elements in array 1 ";
	cin>>n1;
	cout<<"enter the elements of 1st array ";
	for (i=0;i<n1;i++)
	{
		cin>>a1[i];
	}
	cout<<"Enter the number of elements in array 2 ";
	cin>>n2;
	cout<<"enter the elements of 2nd array ";
	for (i=0;i<n2;i++)
	cin>>a2[i];
	m=n1+n2;
	for (i=0;i<n1;i++)
	{
		a3[index]=a1[i];
		index++;
	}
	for (i=0;i<n2;i++)
	{
		a3[index]=a2[i];
		index++;
	}
	cout<<"merged array is ";
	for (i=0;i<m;i++)
	cout<<a3[i]<<" ";
	return 0;
}
