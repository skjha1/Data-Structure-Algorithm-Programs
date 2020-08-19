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
	printf("Enter elements ");
	for (i=0;i<arr.length;i++)
	printf("%d ",arr.A[i]);
}
int Get(struct Array arr, int index )
{
	if (index>=0 && index<arr.length)
	return arr.A[index];
	else 
	return -1;
 } 
int Set (struct Array *arr, int index, int x)
{
	if (index>=0 && index<arr->length)
	arr->A[index]=x;
	return 0;
}

int Max (struct Array arr)
{
	int max=arr.A[0];
	int i;
	for (i=1;i<arr.length;i++)
	{
		if (arr.A[i]>max)
		max=arr.A[i];
	}
	return max;
}
int Min (struct Array arr)
{
	int min=arr.A[0];
	int i;
	for (i=1;i<arr.length;i++)
	{
		if (arr.A[i]<min)
		min=arr.A[i];
	}
	return min;
}
int Sum (struct Array arr)
{
	int sum=0;
	int i;
	for (i=0;i<arr.length;i++)
	sum+=arr.A[i];
	return sum;
}
float Avg(struct Array arr)
{
	return (float)Sum(arr)/arr.length;
}


int main ()

{
	struct Array arr1={{1,3,5,6,77,8,9,22},20,7};
	printf("The element at particular position is %d\n",Get(arr1,2)); // From This we will get the element at index 2
	Set(&arr1,2,15); // This will set the index 0 element with 15
	printf("Maximum in the array is : %d\n",Max(arr1)); // this will give the max value 
	printf("Minimum in the array is : %d\n",Min(arr1)); // This will return the min value 
	printf("The sum of array is : %d\n",Sum(arr1));
	printf("The average value of the array is :%d\n",Avg(arr1));
	Display(arr1);
	return 0;
}

