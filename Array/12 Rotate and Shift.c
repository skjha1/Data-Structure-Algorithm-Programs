#include<stdio.h>

struct Array 
{
	int A[20];
	int length;
	int size;
};
void Display (struct Array arr)
{
	int i;
	for (i=0;i<arr.length;i++)
	printf("%d ",arr.A[i]);
	
}
void Swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void Reverse(struct Array* arr) // function for reversing the array 
{
	int* B; // making a pointer typr array 
	int i, j;
	B = new int[arr->size]; // creating the required size of array in heap 
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++) // keeping all the elements from array a to b in reverse order 
		B[j] = arr->A[i]; // coping element everytime 
	for (i = 0; i < arr->length; i++)
		arr->A[i] = B[i]; // copying back elements to A 
}

void Reverse1(struct Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--) // we will interchange 1st with the last element
		Swap(&arr->A[i], &arr->A[j]); // swapping 1st with the last 

}


int main()

{
	struct Array arr1={{2,3,4,56,66,69,98},7,20};
	// Call any one method to execute 
	Reverse(&arr1); // Shifting 
	Reverse1(&arr1); // 2nd method by swapping 1st with last i.e rotating 
	Display(arr1);
	return 0;
}
