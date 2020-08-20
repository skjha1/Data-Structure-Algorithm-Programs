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
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void Reverse(struct Array *arr)
{
	int *B;
	int i,j;
	B=(int *)malloc(arr->length*sizeof(int));
	for (i=arr->length,j=0,i>=0;i--;j++)
	B[j]=arr->A[i];
	for (i=0;i<arr->length;i++)
	arr->A[i]=B[i];
}
void Reverse1(struct Array *arr)
{
	int i,j;
	for (i=0,j=arr->length-1;i<j;i++,j--)
	{
		swap(&arr->A[i],&arr->A[j]);
	}
}



int main()

{
	struct Array arr1={{2,3,4,56,66,69,98},20,6};
	// Call any one method to execute 
	Reverse(&arr1); // Shifting 
	Reverse1(&arr1); // 2nd method by swapping 1st with last i.e rotating 
	Display(arr1);
	return 0;
}
