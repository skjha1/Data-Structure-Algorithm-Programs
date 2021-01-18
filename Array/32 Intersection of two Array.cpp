#include <iostream>
using namespace std;
struct Array
{
	int *A;
	int size;
	int length;
};


void Display(struct Array* arr)
{
	int i;
	cout << "The elements of the array is " << endl;
	for (i = 0; i < arr->length; i++)
		cout << arr->A[i]<<" ";
}


Array* Intersection(struct Array* arr1, struct Array* arr2)
{
	Array* A = new Array;
	int n = arr1->length + arr2->length;
	A->A = new int[n];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else {
			A->A[k++] = arr1->A[i++];
			j++;
		}
	}
	A->length = k;	
	return A;
}



int main()
{
	struct Array arr;
	struct Array arr1;
	struct Array* arr2;

	int no, i, no1;
	cout << "Enter the size of the array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	cout << "Enter the length of the array " << endl;
	cin >> no;
	arr.length = 0;
	cout << "Enter the elements of the array" << endl;
	for (i = 0; i < no; i++)
	{
		scanf_s("%d", &arr.A[i]);
	}
	arr.length = no;

	cout << "Enter the Size of the 2nd array " << endl;
	cin >> arr1.size;
	arr1.A = new int[arr1.size];
	cout << "Enter the length of the array " << endl;
	cin >> no1;
	arr1.length = 0;
	cout << "Enter the elements of the array " << endl;
	for (i = 0; i < no1; i++)
	{
		scanf_s("%d", &arr1.A[i]);
	}
	arr1.length = no1;



	arr2 = Intersection(&arr, &arr1);
	Display(arr2);


	return 0;
}
