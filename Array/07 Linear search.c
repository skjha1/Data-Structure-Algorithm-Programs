#include<stdio.h>
struct Array {
	int A[20];
	int length;
	int size;
	
};
void Display (struct Array arr)
{
	int i;
	printf("\nEnter elements\n");
	for (i=0;i<arr.length;i++)
	printf("%d ",arr.A[i]);
}
int LinearSearch (struct Array arr, int key)
{
	int i;
	for (i=0;i<arr.length;i++)
	{
		if (key==arr.A[i]) // formula 
		return i;
	}
	return -1;
}
int main ()
{
	struct Array arr1= {{2,3,4,2,3,4,5,88,9	},20,5	};
	printf("The element is at %dth index",LinearSearch(arr1,88));
	Display(arr1);
	return 0;
}
