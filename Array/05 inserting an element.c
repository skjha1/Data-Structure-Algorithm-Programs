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
	cout<<"printing all the elements "<<endl;
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

int main() {
	int no;
	struct Array arr;
	cout << "Enter the size of the array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	arr.length = 0;
	cout << "Enter the length of array" << endl;
	cin >> no;
	cout << "Enter all the elements of array" << endl;
	for (int i = 0; i < no; i++)
		cin >> arr.A[i];
	arr.length = no;
	Add(&arr, 10);
	Insert(&arr,3,25);
	Display(arr);

	return 0;
}
