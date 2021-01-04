#include <iostream>
using namespace std; 

struct Array
{
	int* A;
	int size;
	int length;
};

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Display(struct Array* arr)
{
	int i;
	for (i = 0; i < arr->length; i++)
		cout << arr->A[i]<<" ";

}
int Partition(struct Array* arr, int l, int h)
{
	int pivot = arr->A[l];
	int i = l,j=h;

	do
	{
		do { i++; } while (arr->A[i] <= pivot);
		do { j--; } while (arr->A[j] > pivot);
		if (i < j)	
			Swap(&arr->A[i], &arr->A[j]);

	} while (i < j);
	Swap(&arr->A[l], &arr->A[j]);
	return j;
}

void Quicksort(struct Array* arr, int l, int h)
{
	int j;
	if (l < h)
	{
		j= Partition(arr, l, h);
		Quicksort(arr, l, j - 1);
		Quicksort(arr, j + 1, h);

	}
}

int main()
{
	struct Array arr;
	int no;
	cout << "Enter the size of the array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	cout << "Enter the length of the array " << endl;
	cin >> no;
	arr.length = 0;

	

	cout << "Enter the emements of the array " << endl;
	for (int i = 0; i < no; i++)
		cin >> arr.A[i];
	arr.length = no;
	Quicksort(&arr, 0, no);
	Display(&arr);
	return 0;

}
