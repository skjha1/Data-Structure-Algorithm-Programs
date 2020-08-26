#include<stdio.h>
struct matrix {
	int A[10];
	int n;
};// it is going to modify the matrix so it shoud be call by address  so ptr is taken 
void set (struct matrix *m  ,int i , int j, int x) // i,j is for index  at which you want to set elements, xis what is the element you want to insert  
{
	if (i==j) // as we are going to take only non zero elements so index sud be equal
	m->A[i-1]=x; // store elemnts at diag	
}
int get(struct matrix m ,int i, int j)
{
	if (i==j)
	return m.A[i-1];
	else
	return 0;
}
void Display (struct matrix m)
{
	int i,j;
	for (i=0;i<m.n;i++)
	{
		for (j=0;j<m.n;j++)
		{
			if (i==j)
			printf("%d ",m.A[i]);
			else 
			printf("0 ");
			
		}
		printf("\n");
	}
}



int main ()
{
	struct matrix m;
	m.n=4;
	set (&m,1,1,5);set(&m,2,2,7);set(&m,3,3,8);set(&m,4,4,1);set (&m,5,5,2); // passing argument to diag matrix
	printf("%d \n",Get(m,2,2)); // for slicing matrix 
	Display(m);
	return 0;
}
