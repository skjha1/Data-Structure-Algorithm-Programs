#include<iostream>
using namespace std;
struct Array {
	int* A;
	int size;
	int length;
};


void Count_duplicate_unsorted_hash(struct Array* arr) {
	int low = Min(arr);
	int high = Max(arr);
	int* H;
	H = new int[high];;
	for (int i = 0; i < high; i++) H[i]={ 0 }; // initialise hash table with zero
	for (int i = 0; i < arr->length; i++) 
		H[arr->A[i]]++; // for every element go to that particular index and make increment everytime 
		for (int i = low; i <= high; i++) // traverse through the whole hash table and check the elements 
		{

			if (H[i] > 1) // if hash table elements is greater then 1 that is there is the duplicate element in the array 
				cout << i << " is appearing for " << H[i] << " Times" << endl; // print the duplicate and also print its frequency
		}
	
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
  
	Count_duplicate_unsorted_hash(&arr);


	// Display(arr);
	return 0;

}
