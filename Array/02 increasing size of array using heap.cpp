/* Normal array is created in stack 
and stack used memory array cannot be change 
tht is we can not incresae the size of array  */

#include <stdio.h>
#include<stdlib.h>
int main ()
{
	int *p,*q; // Taking two pointers
	int i;
	p=(int *)malloc(5*sizeof(int)); // array is created in heap memory 
	p[0]=9;p[1]=7;p[2]=22;p[3]=11;p[4]=12;
	
	q= (int *) malloc(10*sizeof(int)); // increasing size of array in heap memory
	
	for (i=0;i<5;i++)
	q[i]=p[i];
	
	free(p);
	p=q;
	q=NULL;
	
	for (i=0;i<5;i++)
	printf("%d \n",p[i]);
	return 0;
}
