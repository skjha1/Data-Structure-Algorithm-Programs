#include<iostream>
using namespace std;
struct Array {
	int* A;
	int size;
	int length;
};

void SingleMissingNumber1(struct Array* arr) {
	int low = arr->A[0]; // take the 1st elelmt of the array 
	int difference = low - 0;// the difference should be constant if not then add the index & diffence to get missing number 
	
	for (int i = 0; i < arr->length; i++)
	{
		if (arr->A[i] - i != difference) {
			cout << "Missing element is " << i + difference;
			break;
		}

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
	SingleMissingNumber1(&arr);
	return 0;

}

// -------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
struct Array 
{
	int A[20];
	int length;
	int size;
};

void Display (struct Array arr)
{
	int i;
	for (i=0;i<arr.length-1;i++)
	printf("%d ",arr.A[i]);
}
int MissingValue(struct Array arr)
{
	int i,sum=0,s1,mv;
	for (i=0;i<arr.length;i++)
	{
		sum=sum+arr.A[i];
		s1=arr.length*(arr.length+1)/2;
		mv=s1-sum;
	}
	return mv;
	
	
}
int  main ()
{
	struct Array arr1={{1,2,3,4,5,6,8,9,10,11,12},12,20};
	printf("\nThe Missing value is %d \n",MissingValue(arr1));
	Display(arr1);
	return 0;
}
