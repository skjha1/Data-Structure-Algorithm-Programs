/* 

Array
Find Largest Element in an Array
Take N number of elements in an array and display the largest element in the array
5
10 200 20 2 4
Largest element=200
7
-10 20 -6 40 4 6 1
Largest element=40
6
2 12 -8 80 40 100
Largest element=100

*/
#include<iostream>
using namespace std;
int main ()
{
	int i,A[10],no;
	int min=A[0];
	cin>>no;
	for(i=0;i<no;i++)
	{
		cin>>A[i];
		if (A[i]>min)
		{
			min=A[i];
			
		}
	}
	cout<<"Largest element= "<<min;
	return 0;
}
