#include<iostream>
using namespace std;

void Quicksort(int A[], int s)
{
	int j = 0, i;
	for (i = 0; i < s; i++)
		if (A[i] < 0)
			if (i != j) {
				swap(A[i], A[j]);
				j++;
			}

}
void printarray(int A[], int s)
{
	int i;
	for (i = 0; i < s; i++)
		cout << A[i] << " ";
}
int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Quicksort(arr, n);
	printarray(arr, n);
	return 0;
}