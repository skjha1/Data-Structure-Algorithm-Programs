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

int IsSorted(struct Array* arr)
{
	for (int i = 0; i < arr->length - 1; i++) 
	{
		if (arr->A[i] > arr->A[i + 1]) // if 1st element is greater then 2nd element then it will k/as not sorted so return 0 
			return 0;
	}
	
	return 1; // if everything is ok and the element came successfully out of loop means it is sorted return 1 for thet 
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
	cout<<IsSorted(&arr);
 return 0;
}
