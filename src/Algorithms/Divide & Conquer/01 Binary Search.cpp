#include <iostream>
#include<stdlib.h>
using namespace std;
struct Array
{
	int* A;
	int size;
	int length;
};
// it is a Divinde and conque approach 
// Binary Search Using iteration 
int BinarySearch(struct Array* arr, int l, int h, int key)
{
	int mid;
	while (l <= h)
	{
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
// Binary Search using Recursion 
int RBinarySearch(struct Array* arr, int l, int h, int key)
{
	int mid;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			return RBinarySearch(arr, l, mid - 1, key);
		else
			return RBinarySearch(arr, mid + 1, h, key);
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
	
	cout<<"The key is at index "<<BinarySearch(&arr,0,arr.length-1,155)<<endl;
	cout<<"The key is at index by recursion is "<<RBinarySearch(&arr,0,arr.length-1,1)<<endl;
	
	return 0;

}
