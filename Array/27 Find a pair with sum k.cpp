#include<iostream>
using namespace std;
int main ()
{
	int A[10]={1,2,4,5,6,8,10,12,14,15};
	int n =sizeof(A)/sizeof(int);
	int k=10 ;// sum of pair of element is 10
	int i,j;
	i=0;
	j=n-1;	
	while (i<j)
	{
	
			if (A[i]+A[j]==k)
			{
				cout<<A[i] <<"+"<<A[j]<<"="<<k<<endl;
				i++;
				j--;
			}
			else if (A[i]+A[j]<k) 
			{
			i++;
			} // increment i if the sum of two element is less than k
			else
			j--;//decremnt j if the sum of two elements is greater than k
		}

	cout<<endl;
	return 0;
}
