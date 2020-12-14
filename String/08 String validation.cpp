#include <iostream>
using namespace std;
int Valid(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >= 48 && s[i] <= 57))
			return 0;
	}
	return 1;
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

	if (Valid(s) == 1)
		cout << "String is valid";
	else
		cout << "String is invalid";




	return 0;

}
