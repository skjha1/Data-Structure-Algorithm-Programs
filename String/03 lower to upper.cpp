#include<iostream>
using namespace std;
int main ()
{
	char A[]="shivendra";
	int i;
	for (i=0;A[i]!='\0';i++)
	{
		A[i]=A[i]-32;
	}
	cout << "Changing in upper case"<< endl<< A;
}
