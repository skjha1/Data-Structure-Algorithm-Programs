#include<iostream>
using namespace std;
int main()
{
	int a[11] = { 6,7,8,9,10,12,13,14,15,16,17 };
	int n = sizeof(a) / sizeof(int);
	int diff = a[0];									//initialising diff with fisrt element of the array

	//We will check the difference between the index element and array index
	//Wherever the difference wiil not be equal to diff, an element is missing there

	for (int i = 0; i < n; i++)
	{
		if (a[i] - i != diff)					//checking the difference betweeen the index element and array index if it is equal to diff or not
		{
			cout << "Missing element is: " << i + diff << endl;
			diff++;														//incrementing the diff value since from now on difference will be an updated value
		}
	}
	cout << endl;
	return 0;
}
