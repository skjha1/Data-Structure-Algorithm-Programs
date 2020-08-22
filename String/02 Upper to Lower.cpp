#include<iostream>
using namespace std;
int main ()
{
	char A[]="SHIVENDRA";
	int i;
	for (i=0;A[i]!='\0';i++)
	{
		A[i]=A[i]+32;		
	}
	cout<<"Changing upper case to lower "<<endl<<A;
	return 0;
}
