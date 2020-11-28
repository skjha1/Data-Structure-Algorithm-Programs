#include <iostream>
#include <stdlib.h>
using namespace std;

struct Array
{
	int* A;
	int size;
	int length;
};

void Display(struct Array arr)
{
	int i;
	cout << "The elements of array are " << endl;
	for (i = 0; i < arr.length; i++)
		cout << arr.A[i] << " ";
}
void append(struct Array *arr, int val)
{
	arr->A[arr->length] = val;
	arr->length++;
}
void insert(struct Array* arr, int index, int val)
{
	int i;
	for (i = arr->length; i > index; i--)
		arr->A[i] = arr->A[i - 1];
	arr->A[index] = val;
	arr->length++;
}
void Delete(struct Array* arr, int index)
{
	int i;
	int x;
	x = arr->A[index];
	for (i = index; i < arr->length; i++)
		arr->A[i] = arr->A[i + 1];
	arr->length--;
}
int main()
{
	struct Array arr;
	cout << "Enter the size of Array"<<endl;

	scanf_s("%d", &arr.size);
	arr.A = new int[arr.size];
	arr.length = 0;
	int no;
	cout << "Enter the length of Array" << endl;
	scanf_s("%d",&no);
	cout << "Enter the elements of the array" << endl;
	for (int i = 0; i < no; i++)
		scanf_s("%d", &arr.A[i]);
	arr.length = no;
	Display(arr);
	append(&arr, 15);
	cout <<endl<<"Elements after Appending the Array is "<< endl;
	Display(arr);
	
	insert(&arr, 3, 55);
	cout <<endl<<"Elements after insertion is "<< endl;
	Display(arr);
	Delete(&arr, 3);
	cout <<endl <<"Elements after deltion is "<<endl;
	Display(arr);
	return 0;



}
