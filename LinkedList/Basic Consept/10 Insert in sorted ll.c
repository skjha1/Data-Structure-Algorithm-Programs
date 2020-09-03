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
void Sortedinsert(struct Node* p, int x)
{
	struct Node* t, * q = NULL;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;/* first node is ready*/
	t->next = NULL; 
	if (first == NULL)
	{
		first = t;
	}
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}
}

int main ()
{
	int a[]= {10,20,30,40,50};
	Create (a,sizeof (a)/sizeof(int));
	Sortedinsert (first,35);
	Display(first);
	printf("\n");
	return 0;
}
