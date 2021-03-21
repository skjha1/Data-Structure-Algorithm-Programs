#include<iostream>
using namespace std;
struct Array {
	int* A;
	int size;
	int length;
};
void SingleMissingElement(struct Array* arr) {
	int sum = 0;
	int n = arr->A[arr->length-1]; // this denotes the last element of the array
	for (int i = 0; i < arr->length; i++)
	{
		sum += arr->A[i]; // sum of the existing array 
	}
	// (n*(n+1))/2 ----> Gives the total sum upto that number 
	int target = (n * (n + 1)) / 2- sum;
	cout << "The missing number is " << target;

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
	SingleMissingElement(&arr);
	return 0;

}
