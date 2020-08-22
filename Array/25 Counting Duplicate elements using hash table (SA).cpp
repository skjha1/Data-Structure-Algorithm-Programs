#include<iostream>
using namespace std;
int main ()
{
	int i;
	int A[15]={1,2,4,5,6,7,8,8,8,8,9,10,10,10};
	int H[15]={0}; // Creating A hash table of as all elements As zero 
	
	for (i=0;i<15;i++) // ----------- n
	{
		H[A[i]]++;
	}
	for (i=0;i<15;i++) // ----------------n = n+n=2n
	{
		if (H[i]>1)
		cout<<i<<" Is appeaaring "<<H[i]<<" Times"<<endl;
		
	}
	
	return 0;
	
}
// Time Complexity is O(n)
