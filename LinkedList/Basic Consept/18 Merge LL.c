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
void RDisplay(struct Node* p)
{
	if (p!=NULL)
	{
		printf("->%d", p->data);
		RDisplay(p->next);
	}
}



void Merge(struct Node* p, struct Node* q)
{
	struct Node* last;
	if (p->data < q->data)
	{
		third = last = p; // move third , last on first 
		p = p->next; // move 1st to the 1st next node 
		third->next = NULL; // make last next to null
	}
	else
	{ 
		// repaet same for 2nd linked list to be merged 
		third = last = q; 
		q = q->next;
		third->next = NULL;
	}
	while (p && q) // repeating process  
	{
		if (p->data < q->data)  // everytime check if p data is smaller then q data if so then 
		{
			last->next = p; // last next sud point on  1st 
			last = p; // last sud be same as first 
			p = p->next; // move 1st to the next node 
			last->next = NULL; // make last next as null

		}
		else // otherwise do same thing for this also 
		{
			// repete same for next ll 
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;

		}
	}
	//this while loop keep on copying elements whichever is smaller and end of while loop remaning will be linked 
	if (p)last->next = p;// if p is not null last next sud point on p 
	if (q)last->next = q;// if q is not null last next sud point on q 

}
int main()
{

	int A[] = { 10,20,40,50,60 };
	int B[] = { 5,15,18,25,30,55 };
	Create(A, sizeof(A)/sizeof(int));
	Create2(B, sizeof(B)/sizeof(int));


	Merge(first, second);	
	printf("Merged elements \n "); 
	Display(third);

	return 0;
}
