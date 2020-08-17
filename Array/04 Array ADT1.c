#include <stdio.h>
struct Array 
{
	int A[20];
	int size;
	int length;
};

int Display (struct Array arr)
{
	int i;
	// enter the elements of an array 
	printf("The elemrnts of array is \n");
	for (i=0;i<arr.length;i++)
	printf("%d ",arr.A[i]);
	printf("\nThe size of the array is %d\n",arr.size);
	printf("The length of the array is %d",arr.length);
	return 0;
}





int main ()
{
	struct Array arr= {{5,6,9,9,7,5},5,20	};
	Display(arr);
	return 0;
}
