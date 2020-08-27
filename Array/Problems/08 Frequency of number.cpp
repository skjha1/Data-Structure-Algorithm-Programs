/* 
Frequency of Numbers
Mani is a shop owner he wants to count the number of balls avilable in the box. The balls are numbered. we need to create a software to accept n number of balls and we need to display the count in each number 
5
2 3 2 15 6
2 occurs 2 times
3 occurs 1 times
15 occurs 1 times
6 occurs 1 times
7
5 6 6 7 11 14 15
5 occurs 1 times
6 occurs 2 times
7 occurs 1 times
11 occurs 1 times
14 occurs 1 times
15 occurs 1 times
5
7 8 9 10 2
7 occurs 1 times
8 occurs 1 times
9 occurs 1 times
10 occurs 1 times
2 occurs 1 times
*/
#include<iostream>
using namespace std;
int main ()
{
	int  no,i,j,count=1;
	int A[100];
	cin>>no;
	for (i=0;i<no;i++)
	cin>>A[i];

	for(i=0;i<no;i++)
	{
		for (j=0;j<no;j++)
		{
			if (A[i]==A[j] && i!=j && A[i]!=-1){
			count++;
			A[j]=1-A[j];
		}
		}
		if (A[i]>=0)
		cout<<A[i]<<" Occurs "<<count <<" Times "<<endl;
		count=1;		
	}
	
	return 0;
}
