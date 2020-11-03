#include <iostream>
using namespace std;
struct Array
{
	int A[10];
	int size;
	int length;
};
void Display(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length; i++)
		cout << arr.A[i] << " ";
}
void Add(struct Array *arr , int x) // element to be inserted 
{
	if (arr->length < arr->size)
		arr->A[arr->length++] = x; // increment the size of array and fit the elements // it will take the constant time 
}
void Insert(struct Array* arr, int index, int x) // the index at which we want to enter // and the value we want tpo enter 
{
	int i;
	for (i = arr->length; i > index; i--) // we will strat from last of the array and shift the elements upto the given index 
	{
		arr->A[i] = arr->A[i - 1]; // shifting the elements to next  // i is on some index and copy the value from previous index 
	}
	arr->A[index] = x; // set the value at the particular index 
	arr->length++; // increment the size of length 
	// work done shifting of elelmets and copying elements 
	// best case : --------------- min : O(1) // there may be zero shifting 
	// worst case : --------------- max : O(n)// there may be n shifing 

}

int main()
{
	struct Array arr1 = { {2,3,4,5,6},10,5 };
	Add(&arr1, 10);
	Insert(&arr1, 0, 12);
	Display(arr1);
	return 0;
}
