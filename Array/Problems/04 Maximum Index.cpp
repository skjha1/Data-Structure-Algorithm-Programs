/* Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)
 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.


Output:

Print the maximum difference of the indexes i and j in a separate line.


Constraints:

1<=T<=30
1<=N<=1000
0<=A[i]<=100

1
2
1 10
1
1
4
2 5 7 9
3


Code by @author Shivendra K jha 

*/
#include <iostream>
using namespace std;
int main()
{ int t,a[1000];
  cin>>t;
 
 while(t--){
	int n,max=-1,i=0;
  	cin>>n;
   int n1=n;
   while(n--)
   {
    cin>>a[i];
     i++;
   }
   for(int i=0;i<n1;i++)
   {
   for(int j=0;j<n1;j++)
   {
   		if(a[i]<=a[j]) 
        {
          if(j-i>max)  max = j-i;
        }
   }
    
   }
 cout<<max;
 }
   return 0;
 
 }

