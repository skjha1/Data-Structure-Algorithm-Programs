//initialising diff with first index element of array

	//We will check for the differnce between the index element and the array index
	//Wherever the difference will not be equal, a missing element is there
	//will increment diff till the difference a[i]-i not equal to diff to continue as soon as we find the missing element

#include<iostream>
using namespace std ;
int main ()
{
	int A[11]= { 6,7,8,9,11,12,15,16,17,18,19 };
	int diff=A[0];
	int n= sizeof(A)/sizeof(int);
	for (int i=0;i<n;i++)
	{
		if (A[i]-1!=diff)
		{
			while (diff<A[i]-i)
			{
				cout<<"Missing Element is "<<i+diff<<endl;
				diff++;
			}
		}
	}
	return 0;
	
}
