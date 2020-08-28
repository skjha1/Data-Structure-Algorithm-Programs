/*
Find median in a stream
Given an input stream of n integers the task is to insert integers to stream and print the median of the new stream formed by each insertion of x to the stream.

Example

Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

Input:
The first line of input contains an integer N denoting the no of elements of the stream. Then the next N lines contains integer x denoting the no to be inserted to the stream.

Output:
For each element added to the stream print the floor of the new median in a new line.

Constraints:
1<=N<=10^5+7
1<=x<=10^5+7
4
5
15
1 
3
5
10
5
4
4
8
20
2
5
8
14
8
6

*/

#include <stdio.h>
int main()
{  int n,i;
 
 scanf("%d",&n);
 int arr[n];
 for(i=0;i<n;i++){
 scanf("%d",&arr[i]);
   }
 int sum=arr[0];
 printf("%d\n",arr[0]);
 for(i=1;i<n;i++){
 sum=(sum+arr[i])/2;
   printf("%d\n",sum);
 
 
 }
	return 0;
}
