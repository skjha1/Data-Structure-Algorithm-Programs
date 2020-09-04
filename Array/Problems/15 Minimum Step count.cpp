/* 
Minimum number of jumps
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains a number n denoting the size of the array.
Next line contains the sequence of integers a1,a2,...,an.

Output:
Each separate line showing the minimum number of jumps. If answer is not possible print -1.

Constraints:
1<=T<=30
1<=N<=100
0<=a[N]<=100
1
11
1 3 5 8 9 2 6 7 6 8 9
3
1
11
2 4 6 1 3 5 4 6 7 8 9
3
code by @ shivendra k Jha 
*/


#include <iostream>
using namespace std ;
int main ()
{
	int t; 
	cin >>t;// input the no of test case
	for (int i=0;i<t;i++){
	int no;
	cin>>no; // input no of elements in array 
	int x=no, count=1;
	int a[no];
	for (int j=0;j<no;j++){
		cin>>a[i];
	}
	

	while(x>0){
      int l;
      i=0;
    	l=a[i];
      i=i+l;
      count++;
      x=x-l;
    }
    cout<<count<<"\n";
  }
	return 0;
}
	
	
	
	

