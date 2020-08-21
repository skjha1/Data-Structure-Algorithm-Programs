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
