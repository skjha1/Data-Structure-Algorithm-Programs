#include<iostream>
using namespace std;
struct Array {
	int* A;
	int size;
	int length;
};

void Display(struct Array arr) {
	cout << "The elements of the array is !" << endl;
	for (int i = 0; i < arr.length; i++)
		cout << arr.A[i]<<" ";
}

void Append(struct Array *arr, int x) {
	if (arr->length < arr->size) {
		arr->A[arr->length] = x;
		arr->length++;
	}
}

void Insert(struct Array* arr, int index, int val) {
	for (int i = arr->length; i > index; i--)
		arr->A[i] = arr->A[i - 1];
	arr->A[index] = val;
	arr->length++;
}



int main() {
	struct Array arr;
	int no;
	cout << "Enter the size of the array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	arr.length = 0;
	cout << "Enter the size of the array" << endl;
	cin >> no;
	cout << "Enter the elements of the array " << endl;
	for (int i = 0; i < no; i++) 
		cin >> arr.A[i];
	arr.length = no;

	// Append(&arr, 5);
	//Insert(&arr, 2, 7);
	Display(arr);
	return 0;

}
