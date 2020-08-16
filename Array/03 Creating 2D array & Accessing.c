 // Creating 2-D array 
#include<stdio.h>
#include<stdlib.h>
int main ()
{ // normal delaration and initialization 
	int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}}; // stack memory
	
	// pointer decleration 
int *B[3]; 
int **C; // double pointer , completly in heap memory
int i,j;
	
B[0]=(int *)malloc(4*sizeof(int)); // Creating memory in heap
B[1]=(int *)malloc(4*sizeof(int));
B[2]=(int *)malloc(4*sizeof(int));
	
C=(int **)malloc(3*sizeof(int *));
C[0]=(int *)malloc(4*sizeof(int));
C[1]=(int *)malloc(4*sizeof(int));
C[2]=(int *)malloc(4*sizeof(int));
	
for (i=0;i<3;i++)
{
for (j=0;j<4;j++)
printf("%d ",A[i][j]);
printf("\n");
}
return 0;
}
 
