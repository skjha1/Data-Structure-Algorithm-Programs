#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*first=NULL,*second=NULL,*third=NULL;
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
void Create2(int A[], int n)
{
	int i;
	struct Node* last, * t;
	second = (struct Node*)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;

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


// Concatenating two linkedlist 
void concat(struct Node* p, struct Node* q) // we will take two pointer p will scan through 1st linkedlist reach to end and then  q will start from 2nd after concatenating 
{
	third = p; // make poinetr third on the 1st 
	while (p->next != NULL) // scan through 1st linkedlist and stop at last node it will stop upon last node 
		p = p->next;
		p->next = q; // contaneted 
}


int main()
{
	int A[] = { 10,20,30,40,50 };
	int B[] = { 1,2,3,4,5 };
	Create(A, sizeof (A)/sizeof (int ));
	Create2(B, sizeof(B)/sizeof(int)); // calling 2nd linkedlist 
	printf("First\n");
	Display(first);
	printf("\n\n");
	// 2nd linkedlist
	printf("Second\n");
	Display(second);
	printf("\n\n");
	concat(first, second);
	printf("concatinated \n");

	Display(third);
	printf("\n\n");

	return 0;

}
