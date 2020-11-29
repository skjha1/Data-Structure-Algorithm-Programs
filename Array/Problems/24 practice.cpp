#include <iostream>
#include<stdlib.h>
using namespace std;
struct Array
{
	int* A;
	int size;
	int length;
};
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void append(struct Array *arr, int val)
{
	arr->A[arr->length] = val;
	arr->length++;
}
void Display(struct Array arr)
{
	int i;
	cout << "the elements of the array" << endl;
	for (i = 0; i < arr.length; i++)
		cout << arr.A[i]<<" ";
}
void Insert(struct Array* arr, int index, int val)
{
	int i;
	for (i = arr->length; i > index; i--)
	{
		arr->A[i] = arr->A[i - 1];
	}
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
int LinearSearch(struct Array *arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			return i;
		}
			
	}
	return -1;
}
// improved linearsearch 
// this is also known as move to first or move to head 
int MovetofirstLS(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])

		{
			swap(&arr->A[i], &arr->A[0]);
			return i;
		}
	}
	return -1;
}
// improved LS it is known as tranposition 
int ILinearSearch(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i]) {
			swap(&arr->A[i], &arr->A[i - 1]);
			return i-1;
		}

	}
	return -1;
}

int BinarySearch(struct Array* arr, int l, int h, int key)
{
	int mid;
	while (l <= h) {
		mid = (l + h) / 2;

		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}
int RBinarysearch(struct Array* arr, int l, int h, int key )
{
	int mid = 0;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			return RBinarysearch(arr, l, mid - 1, key);
		else
			return RBinarysearch(arr, mid + 1, h, key);
	}
	return -1;
	
}


int main()
{
	struct Array arr;
	cout << "Enter the size of the array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	int no;
	cout << "Enter the length of array " << endl;
	cin >> no;
	arr.length = 0;
	cout << "Enter the elements of the array" << endl;
	for (int i = 0; i < no; i++) {
		cin >> arr.A[i];
	}
	arr.length = no;
	//Display(arr);
	//append(&arr, 55);
	//cout << " After appending " << endl;
	//Display(arr);
	//Insert(&arr, 2, 99);
	//cout << " The array after inserting is " << endl;
	//Display(arr);
	//Delete(&arr, 2);
	//cout << "Array after delation from that particular index " << endl;
	//Display(arr);
	//cout<<"The key is at index "<<LinearSearch(&arr,89)<<endl;
	//cout<<"The key is at index "<<ILinearSearch(&arr,88)<<endl;
	////cout<<"The key is at index "<<MovetofirstLS(&arr,11)<<endl;
	//cout<<"The key is at index "<<RBinarysearch(&arr,0,arr.length-1,155)<<endl;

	return 0;

}