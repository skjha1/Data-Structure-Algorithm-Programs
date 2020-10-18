#include <stdio.h>
#include<stdlib.h>
int findMax(int A[], int n) // fxn for finding max from array A // so that we can create a count array of max size
{
	int max = -2147483647;
	int i;
	for (i = 0; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}
void CountSort(int A[], int n)
{
	int i, j, max, * C;

	max = findMax(A, n); // find max element from array 
	C = (int*)malloc(sizeof(int) * (max + 1)); // creatring count array of max size 

	for (i = 0; i < max + 1; i++) // intialise all count array with zero
	{ 
		C[i] = 0;
	}
	for (i = 0; i < n; i++) // count the no of elements present and increment the count array index 
	{
		C[A[i]]++;
	}

	i = 0; j = 0;
	while (j < max + 1) // copy all the elements back to A 
	{
		if (C[j] > 0)
		{
			A[i++] = j;
			C[j]--;
		}
		else
			j++;
	}
}
int main()
{
	int A[] = { 11,13,7,12,16,9,24,5,10,3 }, n = 10, i;

	CountSort(A, n);

	for (i = 0; i < 10; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}
// time comlexity  O (n ) // less time taken // but it is space counsuming algorithm // when the value of elements will be less we will opt this algo