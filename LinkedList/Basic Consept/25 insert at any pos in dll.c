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

// inserting in DLL at a given position 
void Insert(struct Node* p, int pos, int x)
{
	struct Node* t=NULL;
	int i;
	if (pos <0 || pos > Length(p))
		return;
	if (pos == 0) // inserting before 1st node 
	{
		t = (struct Node*)malloc(sizeof(struct Node)); 
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		
		
		for (i = 0; i < pos - 1; i++) // move upto pos-1 time to reach particular node 

			p = p->next; 
		t = (struct Node*)malloc(sizeof(struct Node)); // creating node 
		t->data = x; // fill data
		t->prev = p;
		t->next = p->next;
		
		if (p->next) // Checking wheather there is next node availble or not 
			p->next->prev = t;
			p->next = t;
	

	}

}

int main()
{
	int no, i, A[10],pos,x;
	printf("enter the size of Array\n ");
	scanf_s("%d", &no);
	printf("enter the elements of array\n");
	for (i = 0; i <no; i++)
		scanf_s("%d", &A[i]);
	create(A, no);
	printf("Given DLL is\n ");
	Display(first);
	printf("enter pos to insert  element\n");
	scanf_s("%d", &pos);
	scanf_s("%d", &x);
	
	Insert(first, pos, x);
	Display(first);
	printf("length of linked list is %d", Length(first));
	return 0;
}





