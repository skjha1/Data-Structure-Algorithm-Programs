/* 
Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

Explanation :
Testcase1: sum of elements from 2nd position to 4th position is 12
Testcase2: sum of elements from 1st position to 5th position is 15
*/

#include <iostream>
using namespace std;

int main() {
	int Test_case; // no of test cases
	cin>>Test_case;
	for(int i=0;i<Test_case;i++)
	{
	    int N_size,Sum; // initializing size of array and sum
	    cin>>N_size>>Sum; // taking input
	    int A[N_size];
	    for(int j=0;j<N_size;j++) 
	        cin>>A[j];
	    int pivot=0,sum=0,flag=0;
	    for(int j=0;j<N_size;j++)
	    {
	        sum=sum+A[j];
	        while(sum>Sum)
	        {
	            sum=sum-A[pivot];
	            pivot++;
	        }
	        if(sum==Sum)
	        {
	            cout<<pivot+1<<" "<<j+1<<"\n"; // we got the index from where to where sum is sum 
	            flag=1; 
	            break;
	        }
	    }
	    if(flag==0)
	        cout<<"-1"<<"\n";
	}
	return 0;
}
//time complexity O(n)
