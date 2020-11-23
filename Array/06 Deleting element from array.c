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
		x=arr->A[index]; // first of all take out the element from the particular index you want to del---------------------> taking 1 unit of time 
		for (i=index;i<arr->length-1;i++) // shift the element in forward direnction and stop at length -1 so that array can not have any vacant space 
		arr->A[i]=arr->A[i+1]; // at the place of a[i] copy the next element i.e a[i+1]
		arr->length--;//at last the length will be decreatmented ----------------> 1 unit of time -------> so best time is 1+1 =2 
		
		// min shifting is 0 and max shifting is n ----> Best case time is O(1) -> Worst Case time is ----> O(n)
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
