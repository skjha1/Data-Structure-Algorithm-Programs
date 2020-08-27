/* Array
Average of Array
Find the Average of n numbers using array concept. First line of the Input is the number of Input
5
45 35 38 31 49
39
3
100 200 300
200
2
15 20
17
6
5 5 5 5 5 5
5
*/

#include<iostream>
using namespace std ;
int main ()
{
	int i,no,A[10],sum=0,avg;
	cin>>no; // number of elements in an araay
	for (i=0;i<no;i++)
	{
		cin>>A[i];
		sum+=A[i];
		avg=sum/no; // taking mean of array 
	}
	cout<<avg;
	return 0;
	
}
