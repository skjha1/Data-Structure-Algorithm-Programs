#include <iostream>
using namespace std;

int Length(char s[])
{
	int i, length=0;
	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}

int main()
{
	char* s;
	int l;
	cout << "Enter the Size of the Array " << endl;
	cin >> l;
	s = new char[l];
	cout << "Enter the String " << endl;
	cin >> s;

	cout<<"The Length of the string is "<<Length(s);
	return 0;

}