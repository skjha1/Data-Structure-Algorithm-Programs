#include <stdio.h>
#include <stdlib.h>
int main()
{
	int A[5] = { 1,2,3,4,5 }; // this is allocated inside stack memory 
	int* p; // pointer of array
	int i;
	p = (int*)malloc(5 * sizeof(int)); // dynamically createing array inside heap 
	p[0] = 1; // initializing all the terms in array
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;

	for (i = 0; i < 5; i++) // iteration for normal array 
	{
		printf("%d ", A[i]);
	}
	printf("\n");
 	for (i = 0; i < 5; i++) // iteration for the dynamic array 
	{
		printf("%d ",p[i]);
	}
	return 0;
}
