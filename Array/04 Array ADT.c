#include <stdio.h>
#include<stdlib.h>
struct Array
{
	int* A;
	int size;
	int length;
};

// fxn for display all the elements of the array

void Display(struct Array arr)
{
	int i;
	printf("Elements Are\n");
	for (i = 0; i < arr.length; i++)
		printf("%d ",arr.A[i]); // it will display all the elements 
}
int main()
{
	struct Array arr;
	int n; // how many no is going to be inserted 
	int i;
	printf("Enter size of an array ");
	scanf_s("%d", &arr.size);
	arr.A = (int*)malloc(arr.size * sizeof(int)); // dynamically created array 
	arr.length = 0;// intially no elements 
	printf("Enter number of numbers ");
	scanf_s("%d", &n);
	printf("Enter All the elements ");
	for (i = 0; i < n; i++)
		scanf_s("%d", &arr.A[i]); // enter the elements of an array 
	arr.length = n; // set length as n 


	Display(arr);


	return 0;
}
