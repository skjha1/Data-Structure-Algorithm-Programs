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
void Insert1(struct Array* arr, int val)
{
	int i;
	i = arr->length - 1;
	while (arr->A[i] > val) // here we dont know how many times we have to repeat the loop so we used while loop 
	{
		arr->A[i + 1] = arr->A[i]; // go on shifting the elements value is less then array's elements 
		i--;
	}
	arr->A[i + 1] = val; // set the value at a given pos
	arr->length++;
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
  Insert1(&arr, 18);
	Display(&arr);
	


	return 0;
}
