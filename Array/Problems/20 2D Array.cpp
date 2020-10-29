// Two dimensional(2D) Array

#include <iostream>
using namespace std;
int main()
{
	int arr[3] [3];
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("Enter the term to be displayed [%d] [%d] : ",i,j);
			scanf_s("%d",&arr[i][j]);
		}
	}
	// Display Array elements 
	printf("Two dimension elements are : \n ");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++) {
			printf("%d  ", arr[i][j]);
			if (j == 2)
				printf("\n");
		}
	}
	return 0;
}