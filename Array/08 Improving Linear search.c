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
void swap(int *x,int *y)
 {
 int temp=*x;
 *x=*y;
 *y=temp;
 }
int LinearSearch(struct Array *arr,int key)
{
 int i;
 for(i=0;i<arr->length;i++) // iterating through the list 
 {
 if(key==arr->A[i]) // checking whether elements is equal to the key elements or not 
 {
 swap(&arr->A[i],&arr->A[0]); // this is move to 1st method // from this we can reduce time to O(1) // when we will search the same element again 
 return i;
 }
 }
 return -1;
}

int main ()
{
	struct Array arr1= {{2,3,4,2,3,4,5,88,9	},20,5	};
	printf("The element is at %dth index",LinearSearch(&arr1,9));
	Display(arr1);
	return 0;
}
