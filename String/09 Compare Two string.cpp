#include <iostream>
#include <string> 
#include<stdio.h>
using namespace std;

void compare(char s[], char s1[])
{
	int i,j;
	for (i = 0, j = 0; s[i] != '\0' && s1[j] != '\0'; i++, j++)
	{
		if (s[i] != s1[j])
			break;
	}
	if (s[i] == s1[j])
		cout << "Both the strings are equal " << endl;
	else if (s[i] < s1[j])
		cout << "1st one is smaller " << endl;
	else
		cout << "1st is larger " << endl;
}


int main()
{
	char* s;
	char* s1;
	int l;
	cout << "Enter the Size of the Array " << endl;
	cin >> l;
	s = new char[l];
	s1 = new char[l];
	cout << "Enter the 1st String " << endl;
	cin >> s;
	cout << "Enter the 2nd string " << endl;
	cin >> s1;
	compare(s, s1);

	return 0;

}
