/* Search in a matrix
Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . The task is to find whether element x is present in the matrix or not.
Expected Time Complexity : O(m + n)
Input:
The first line of input contains a single integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of two space separated integers N and M, denoting the number of element in a row and column respectively.
Second line of each test case consists of N*M space separated integers denoting the elements in the matrix in row major order.
Third line of each test case contains a single integer x, the element to be searched.
Output:
Corresponding to each test case, print in a new line, 1 if the element x is present in the matrix, otherwise simply print 0.
Constraints:
1<=T<=200
1<=N,M<=30
2
3 3
3 30 38 44 52 54 57 60 69
62
1 6
18 21 27 38 55 67
55
0
1
2
3 3
3 0 8 2 5 4 7 6 9
6
1 3
1 2 3
2
1
1 

@author   Shivendra K jha */


#include<iostream>
using namespace std;
int main ()
{
	int no_of_array,m,n,x,a[100][100];
	cin>>no_of_array;  // Number of Array to be entered 
	for(int i=1;i<=no_of_array;i++)
	{
	cin>>m>>n;  // size of array 
	for(int j=0;j<m;j++) // entering elements in array 
	{
		for (int k=0;k<n;k++)
		cin>>a[j][k];
		
	}
	cin>>x; // number to be checked 
	int count=0;
	for(int j=0;j<m;j++ )
	{
		for (int k=0;k<n;k++)
		{
			if (a[j][k]==x) // checking condn either x in present in array or not
			count++;    // if number is present in array increment the count 
		}
	}
	if (count>0)
	cout<<"1";
	else
	cout<<"0";
}
return 0;
}
