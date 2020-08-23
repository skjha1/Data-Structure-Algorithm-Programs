/* 
iven an array arr[ ] of n integers, construct a Product Array prod[ ] (of same size) such that prod[i] is equal to the product of all the elements of arr[ ] except arr[i].

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[i].

Output:

Print the Product array prod[ ].

Constraints:

1<=T<=10
1<=N<=15
1<=C[i]<=20
2
5
10 3 5 6 2
2
12 20
180 600 360 300 900 
20 12
2
5
1 4 7 9 8
2
1 2
2016 504 288 224 252 
2 1

@auther Shivendra K jha */

#include<iostream>
using namespace std;
int main ()
{
	int test,no,a[10],prod=1;
	cin>>test;
	for (int i=1;i<test;i++)
	cin>>no;
	for (int j=0;j<no;j++)
	{
		cin>>a[j];
		prod=prod*a[j]; // getting product of full array 
		
	}
	for (int k=0;k<no;k++)
	{
		cout<<prod/a[k]<<" "; // removing 1st elements products from final output
		
	}
	cout<<endl;
	return 0;
	
	
}

/* Another code using while loop */

#include <iostream>
using namespace std;
int main()
{int t;
 cin>>t; // enter number of testcase
 while(t--)
 {
    int n,i,prod=1;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
  {
    cin>>a[i];
    prod*=a[i]; // applying operation
  }
  for(i=0;i<n;i++)
  	{
    cout<<prod/a[i]<<" ";// removing a[i](that particular number)
	}
	cout<<endl;}
	return 0;
}
