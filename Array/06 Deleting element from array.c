#include <stdio.h>

struct Array 
{
	int A[10];
	int length;
	int size;
};

int Display(struct Array arr)
{
	int i;
	printf("Elements Are\n");
	for (i=0;i<arr.length;i++)
	printf("%d ",arr.A[i]);
	return 0;
}
int Delete (struct Array *arr, int index)

/* Difference between Dot(.) and Arrow(->) operator:

The Dot(.) operator is used to normally access members of a structure or union.
The Arrow(->) operator exists to access the members of the structure or the unions using pointers. */
{
	int x=0;
	int i;
	if (index>=0 && index <arr->length)
	{
		x=arr->A[index];
		for (i=index;i<arr->length-1;i++)
		arr->A[i]=arr->A[i+1];
		arr->length--;
		return x;
	}
	return 0;
}
int main ()
{
	struct Array arr1={{1,2,3,4,56,5,2},10,5};
	printf("%d\n",Delete(&arr1,0));
	Display(arr1);
	return 0;
}
