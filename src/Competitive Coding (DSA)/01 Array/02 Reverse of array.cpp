#include <iostream>
using namespace std;

void Display(int A[], int  size)
{
	int  i;
	for (i = 0; i < size; i++)
		cout << A[i]<<" ";
}

void Reverse(int A[], int start, int end)
{
	while (start < end)
	{
		int temp = A[start];
		A[start] = A[end];
		A[end] = temp;
		start++;
		end--;
	}
}

int main()
{
	int A[20], i;
	int no = sizeof(int) / sizeof(A[0]);

	cout << "Enter the size of array"<<endl;
	cin >> no;
	cout << "Enter all the elements of the arrry"<<endl;
	for (i = 0; i < no; i++)
		cin >> A[i];
	Reverse(A, 0, no - 1);
	cout << "After reversing array " << endl;
	Display(A, no);
	return 0;
}