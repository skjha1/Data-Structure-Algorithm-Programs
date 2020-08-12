/* Arrays
Search in a matrix
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

*/

#include <iostream>
using namespace std;
int main()
{
  int t,m,n,a[100][100],x;
  cin>>t;  // enter the number of array to be checked
  for(int i=1;i<=t;i++)
  {
    cin>>m>>n;  // order of array
    for(int j=0;j<m;j++) // number of row & column
    {
      for(int k=0;k<n;k++)
      {
        cin>>a[j][k]; // taking array
      }
    }
    cin>>x; // the element which will be checked
    int count=0;
    for(int j=0;j<m;j++)
    {
      for(int k=0;k<n;k++)
      {
        if(a[j][k]==x)  // if elements in the matrix is equal to x (number to be checked)
          count++;
      }
    }
    if(count>0)
      cout<<"1"; // True 
    else
      cout<<"0";  // False
    cout<<"\n";
  }

	return 0;
}
