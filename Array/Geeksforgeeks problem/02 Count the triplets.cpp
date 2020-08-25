/*Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated elements.

Output:
For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".

Constraints:
1 <= T <= 100
3 <= N <= 105
1 <= A[i] <= 106

Example:
Input:
2
4
1 5 3 2
3
3 2 7
Output:
2
-1

Explanation:
Testcase 1: There are 2 triplets: 1 + 2 = 3 and 3 +2 = 5
*/
// here  we are using the consecpt of hasing to reduce time else we need to take one extra for loop for count 
#include<iostream>
using namespace std;
int main()
 {
     int t;
     cin>>t; // number of testcases 
     while(t--)
     {
         long long int k,n,count=0;
         cin>>n;
        int a[n],h[10]={0};//one array to traverse throgh and another hashing array for counting the no of triplets  
         for(int i=0;i<n;i++)
         {
             cin>>a[i]; // entering elements in array 
             h[a[i]]=1; 
         }
         
         for(int i=0;i<n;i++)
         {
             for(int j=i+1;j<n;j++) // it will start from 2nd element
             {
                 k=a[i]+a[j]; 
                 if(h[k]==1)// whenever condition statisfy increase the count by 1 
                 count++;
             }
          }   
          if(count!=0)
          cout<<count<<endl;
          else cout<<"-1"<<endl;
         
         
     }
	return 0;
}
