#include <iostream>
#include <string> 
#include<stdio.h>
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

void Vowelcount(char s[])
{
	int i;
	int vcount=0;
	int Ccount = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
			vcount++;
		else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
			Ccount++;
	}
	cout << "Total number of vowel is " << vcount << endl;
	cout << "Total number of consonant is " << Ccount<<endl;
}

void WordCount(char s[])
{
	int i;
	int word = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' && s[i-1]!=' ' )
			word++;
	}
	cout << "Total word in the sentance is " << word+1;
}

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

void Reverse(char s[], int no)
{
	char* B;
	B = new char[no];
	int i, j;
	for (i = 0; s[i] != '\0'; i++)
	{

	}
	i = i - 1;
	for (j = 0; i >= 0; i--, j++)
		B[j] = s[i];
	B[j] = '\0';
	cout << "The reverse of string is " << B;
}
void Reverse1(char s[])
{
	int i, temp, j;
	for (j = 0; s[j] != '\0'; j++)
	{
	}
	j = j - 1;
	for (i = 0; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
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
	//cin.getline (s,10);

	/*cout<<"The Length of the string is "<<Length(s);*/
	//UtoLCase(s);
	//LtoUCase(s);
	/*MixedCase(s);*/
	//Vowelcount(s);
	/*WordCount(s);*/

	/*if (Valid(s) == 1)
		cout << "String is valid";
	else
		cout << "String is invalid";*/

	/*Reverse(s, l);*/
	Reverse1(s);

	return 0;

}
