//Display a Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*first = NULL;
void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
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
void Display(struct Node* p)  // displaying the elements 
{
	while (p != NULL)
	{
		printf(" %d ", p->data);
		p = p->next;
	}
}
struct Node* LSearch(struct Node* p, int key)
{
	struct Node* q=NULL;

	while (p != NULL)
	{
		if (key == p->data)
		{
			q->next = p->next; // this block of code for move to first 
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;

}
struct Node* RSearch(struct Node* p, int key)
{
	if (p == NULL)
		return NULL;
	if (key == p->data)
		return p;
	return RSearch(p->next, key);

}
int main()
{
	struct Node* temp;
	int A[] = { 3,5,7,10,25,8,32,2 };
	create(A, 8);
	temp = LSearch(first, 8); // this will occupy the 2nd index 
	temp = LSearch(first, 2); // first this will go to 1st index 
	//printf("% d", temp->data);
	Display(first);


	return 0;
}
