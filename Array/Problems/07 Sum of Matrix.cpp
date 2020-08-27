/*
Write a C program to find the sum of two matrices of order 2*2 using multidimensional arrays.
2 2
12 22
10 12
2 2
22 25
23 9
34 47 
33 21
3 3
1 2 3
4 5 6
7 8 9
3 3
1 2 3
4 5 6
7 8 9
2 4 6 
8 10 12 
14 16 18
codeby @ Shivendra kumar jha 

*/
#include<iostream>
using namespace std;
int main ()
{
	int m,n,i,j,A[10][10],S[10][10];
	cin>>m>>n;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		cin>>A[i][j];
	}
	int p,q,B[10][10];
	cin>>p>>q;
		for (i=0;i<p;i++)
	{
		for (j=0;j<q;j++)
		cin>>B[i][j];
	}
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
		
	 	S[i][j] = A[i][j]+B[i][j];
		cout<<S[i][j]<<" ";
	}
	cout<<endl;
	}
	
	return 0;
}
