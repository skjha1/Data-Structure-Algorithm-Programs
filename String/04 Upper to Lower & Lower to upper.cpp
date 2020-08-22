#include<iostream>
using namespace std;
int main ()
{
	char A[]="ShIvEnDRa";
	int i;
	for (i=0;A[i]!='\0';i++)
	{
		if (A[i]>=65 && A[i]<90)
		A[i]+=32;  // This is for changing lower case 
		else if (A[i]>=97 && A[i]<=122)
		A[i]-=32;  // This is for changing upper case
	}
	cout<<"Changing Upper to lower and lower to upper "<<endl<<A;
	return 0;
}
