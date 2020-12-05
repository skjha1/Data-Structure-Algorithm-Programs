	#include<iostream>
using namespace std;

struct Array
{
	int* A;
	int size;
	int length;
};

void Display(struct Array* arr)
{
	int i;
	cout << "the elements of the array is " << endl;
	for (i = 0; i < arr->length; i++)
		cout <<arr->A[i] << " ";
}
  
  void Arrange(struct Array* arr)
{
	int i=0;
	int j = arr->length - 1; // set j to the last of the array element
	while (i < j) {
		while (arr->A[i] < 0) { i++; } //while the array element is less then zero keep increamenting the array
		while (arr->A[j] >= 0) { j--; } //  while the array elemet is greater then zero decreamenting the array from last 
		if (i < j) // and when i is less then j interchange the value 
			Swap(&arr->A[i], &arr->A[j]);
	}
	// time taken is O (n) -- > comparing the elemets total n+2 elements compared 
}

  
  int main()
{
	struct Array arr;
	cout << "Enter the size of Array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];	
	int no;
	cout << "Enter the length of the array " << endl;
	cin >> no;
	arr.length = 0;	
	cout << "Enter the elements of the array " << endl;
	for (int i = 0; i < no; i++)
		cin >> arr.A[i];
	arr.length = no;
  Arrange(&arr);
  Display(&arr);
	return 0;
}
