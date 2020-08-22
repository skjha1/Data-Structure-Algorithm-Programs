#include<iostream>
using namespace std;
int main ()
{
	int A[10]={1,6,2,4,5,10,11,12,3,7};
	int k=10;
	int H[20]={0};  // Initialize the size of hashing array with the largest element in array A ;
	int n= sizeof(A)/sizeof(int);
	
	for (int i=0;i<n;i++)
	{
		if (H[k-A[i]]!=0 && k-A[i]>=0 )
		cout<<A[i]<<"+"<<k-A[i]<<"="<<k<<endl;
		H[A[i]]++;
		
	}
	return 0;
}
