#include<iostream>
using namespace std;
int main()
{
	int a[8] = { 1,2,3,5,6,8,12,14 };
	int n = sizeof(a) / sizeof(int);
	int h[14] = { 0 };					//Hash table with size equal to the largest element present in the array a ie 14
	for (int i = 0; i < n; i++)			//for loop to increment values at indices equal to the element in first array
		h[a[i]]++;	
	for (int i = 1; i <= 14; i++)
	{
		if (h[i] == 0)					//to check which indices are 0 so those elements are missing
			cout << "Missing element is: " << i << endl;
	}
	cout << endl;
	return 0;
}
