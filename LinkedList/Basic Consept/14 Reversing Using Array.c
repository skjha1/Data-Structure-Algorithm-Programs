#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*first=NULL;
void Create(int A[], int n)
{
	int i;
	struct Node* last, * t;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void Display(struct Node* p)
{
	while (p != NULL)
	{
		printf("->%d", p->data);
		p = p->next;
	}
}
int count(struct Node* p)
{
	int c = 0;
	while (p != NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}

// reversing ll using array 
void Reverse1(struct Node* p) // pointer to 1st node 
{
	int* A,i=0; // for storing reversed linkedlist we need an array & and its size is not known so we will find the length of ll // for that we created an array dynamically 
	struct Node* q=p; // for traversing we will take one more pointer that will help in traversing 
	A = (int*)malloc(sizeof(int) * count(p)); // create an array size is length of ll // size of int type // mul by length of ll // array is created 
	while (q != NULL) 
	{
		A[i] = q->data; // everytime copy data from q to array 
		q= q->next; // and move q to next 
		i++; // increment i

	}
	// once it reach end of linkedlist all element copied in array 
	q = p;// q sud again strat from 1st pointer  i.e p
	i--; // i shoud go back
	while (q != NULL)
	{
		q->data = A[i]; // we will copy in reverse manner 
		q = q->next; // move q to next 
		i--;

	}

}


int main()
{
	int A[] = { 10,20,30,40,50 };
	Create(A, sizeof (A)/sizeof (int ));
	Reverse1(first);
	Display(first);
	printf("\n\n");

	return 0;

}
