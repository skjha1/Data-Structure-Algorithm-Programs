#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node* prev;
	int data;
	struct Node* next;
}*first=NULL;
void create(int A[],int n)
{
	struct Node* last, * t;
	int i;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0]; // Take data from 1st loc of array passed ;
	first->prev = first->next = NULL; // set both pointer as NULL;
	last=first; // move last to first ;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		// As i have to Always insert a new node after the last node so ;
		//t - next = last->next is same as t->next = head;
		t->next = last->next;// this means the newly created node is attached at the end of the list(i.e appended to the last node); // last node will always contain NULL so it is same thing.
		t->prev = last;
		last->next = t;
		last = t;

	}

}
void Display(struct Node* p)
{
	while (p)  //means repeat the loop until p is not equals to null. I.e until we reach the last node, we want to traverse the list
	{
		printf("->%d ", p->data);
		p = p->next;

	}
	printf("\n");
}
int Length(struct Node* p)
{
	int len = 0;
	while (p)
	{
		len++;
		p = p->next;

	}
	return len;
}
struct Node *Middleelement(struct Node* p)
{
	struct Node* q;
	q = p;
	while (q)
	{
		q = q->next;
		if (q)
			q= q->next;
		if (q)
			p = p->next;
	}
	return p;
}


int main()
{
	int no, i, A[10],pos;
	struct Node* t;
	printf("enter the size of Array\n ");
	scanf_s("%d", &no);
	printf("enter the elements of array\n");
	for (i = 0; i <no; i++)
		scanf_s("%d", &A[i]);
	create(A, no);
	printf("Given DLL is\n ");
	Display(first);
	t=Middleelement(first);
	printf("\n middle elements is %d\n",t->data);
	printf("length of linked list is %d", Length(first));
	return 0;
}

