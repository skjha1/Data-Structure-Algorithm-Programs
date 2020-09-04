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


//reversing using Recursion 
void Rreverse(struct Node* q, struct Node* p) // taking two pointer p and q ; p will always ahead and q will follow that;
{
	if (p != NULL)
	{
		Rreverse(p, p->next); //  passing two pointer
		p->next = q;// while recturnig  it will make p next as q 
	}
	else
		first = q; // while p i null make first as q ;
}

int main()
{
	int A[] = { 10,20,30,40,50 };
	Create(A, sizeof (A)/sizeof (int ));
	Rreverse(NULL,first);
	Display(first);
	printf("\n\n");

	return 0;

}
