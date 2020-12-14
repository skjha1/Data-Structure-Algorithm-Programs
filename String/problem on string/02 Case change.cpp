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

void UtoLCase(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		s[i] += 32;
	}
	cout <<"Changing uppar case to lower case "<<endl<< s;
}
void LtoUCase(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		s[i] -= 32;
	}
	cout << "Changeing lower case to upper case " << endl << s;
}

void MixedCase(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			s[i] += 32;
		}
		else if (s[i] >= 97 && s[i] <= 122)
		{
			s[i] -= 32;
		}
		else
			break;
	}
	cout << s;
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

	/*cout<<"The Length of the string is "<<Length(s);*/
	//UtoLCase(s);
	//LtoUCase(s);
	/*MixedCase(s);*/



	return 0;

}
