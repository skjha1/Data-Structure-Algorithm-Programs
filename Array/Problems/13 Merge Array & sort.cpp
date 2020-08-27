/* 
Merge
There are two sorted arrays. First one is of size m+n containing only m elements. Another one is of size n and contains n elements. Merge these two arrays into the first array of size m+n such that the output is sorted.

Input:
The first line contains the size of m+n array.
The second line contains elements of m+n array.The elements with "-1" denotes the vacant spaces to be filled.
The third line contains size of n array.
The fourth line contains the size of the n array.

Output:
Output contains m+n arrays in sorted order
5
4 5 -1 -1 7
2
8 10
4 5 7 8 10
6
7 -1 -1 10 -1 -1
4
9 8 13 12
7 8 9 10 12 13
4
1 -1 -1 9
2
80 98
1 9 80 98
*/

#include<iostream>
#include<algorithm>
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
	sort(a3,a3+m);

	cout<<"merged array & after sorting ";
	for (i=0;i<m;i++)
	{
		if (a3[i]>0)
		cout<<a3[i]<<" ";
		}	
	
	return 0;
}
