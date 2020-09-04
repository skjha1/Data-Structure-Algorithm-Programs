	
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
void RDisplay(struct Node* p)
{
	if (p!=NULL)
	{
		printf("->%d", p->data);
		RDisplay(p->next);
	}
}
// using sliding pointer 
void Reverse2(struct Node* p) // 1st node pointer
{
	struct Node* q = NULL, *r = NULL; // we requre three pointer p,q,r
	p = first; 
	while (p != NULL)
	{/*
	 sliding pointer */
		r = q; // r  sud come upon q
		q = p;// q sud come upon p
		p = p->next;// p sud move to next node 
		q->next = r;// q next sud points on 
	}
	first = q; // once we came out of while loop // 1st ointer sud point on q 

}


int main()
{
	int A[] = { 10,20,30,40,50 };
	Create(A, sizeof (A)/sizeof (int ));
	Reverse2(first);
	Display(first);
	printf("\n\n");

	return 0;

}
