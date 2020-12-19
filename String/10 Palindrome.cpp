#include <iostream>
#include <string> 
#include<stdio.h>
using namespace std;

char palindrome(char Arr1[])
{
	int i, j, k = 0;
	for (i = 0; Arr1[i] != '\0'; i++) {}
	j = i - 1;
	while (k <= j)
	{
		if (Arr1[k] != Arr1[j])
		{
			printf("Not a palindrome.");
			return 0; // stop the function here
		}
		else
		{
			k++;
			j--;
		}

	}
	printf("Palindrome.\n");
	return 0;
}


int main()
{
	char* s;
	int l;
	cout << "Enter the Size of the Array " << endl;
	cin >> l;
	s = new char[l];
	cout << "Enter the 1st String " << endl;
	cin >> s;

	palindrome(s);

	return 0;

}
