#include<iostream>
using namespace std ;
int main ()
{
	int i,j;
	int A[13]={3,6,8,8,8,10,12,12,12,15,20,20,20};
	
	for(i=0;i<13;i++)
	{
		if (A[i]==A[i+1])
		{
			j=i+1;
			while (A[j]==A[i])
			j++;
			cout<<A[i]<<" Appering "<<j-i<<" Times "<<endl;
			i=j-1;
		}
	}
	cout<<endl;
	return 0;
}
// Time complexity is O(n) 
// Here while loop is negligible as compared to for loop
