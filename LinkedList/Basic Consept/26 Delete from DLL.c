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
void Insert(struct Node* p, int pos,int x)
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
int Delete(struct Node* p, int pos)
{
	struct Node* q; // for deletion i may need a temp pointer that is q 
	int x = -1; 
	int i;
	if (pos<1 || pos > Length(p))
		return -1;
	if (pos == 1)
	{
		p = first; // take pointer on 1st node 
		first = first->next; // move 1st to 1st next 
		x = p->data;// take out data;
		free(p); // delete the element 
		if (first)// whether it is 1st or not // or it is really pointing on 1st or not 
			first->prev = NULL; 
		printf("\nthe deleted node is %d", x);
		
	}
	else
	{
		p = first; // p's upon 1st 
		for (i = 0; i < pos - 1; i++) // move p upto pos -1 times 
			p = p->next; // moving p to next-next-next
		p->prev->next = p->next; // linking with node after deleted one ->
		if (p->next)
			p->next->prev = p->prev; // linking node // <-
		x = p->data; // take out data 
		free(p); // delete the node 
	}
	printf("the deleted element is %d\n", x);
}

int main()
{
	int no, i, A[10],pos;
	printf("enter the size of Array\n ");
	scanf_s("%d", &no);
	printf("enter the elements of array\n");
	for (i = 0; i <no; i++)
		scanf_s("%d", &A[i]);
	create(A, no);
	printf("Given DLL is\n ");
	Display(first);
	printf("enter pos to delete element\n");
	scanf_s("%d", &pos);	
	Delete(first, pos);
	printf("\n After Deleteing DLL is ");
	Display(first);
	printf("length of linked list is %d", Length(first));
	return 0;
}
