#include<iostream>
using namespace std;
int main()
{
	char A[]="My name is    Shivendra";
	int i,word=1;
	for (i=0;A[i]!='\0';i++)
	{
		if (A[i]==' '&& A[i-1]!=' ')  // if whitespace encounter in string it will count word // 2nd cond if more then one whitespace btw 2 conseqitive word it will eliminate
		word++;
	}
	cout<<"Total word is "<<word;
	return 0;
}
