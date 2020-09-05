#include <stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next; // self ref pointer 
}*Head; // global pointer we can pass it as parameter 


void Create(int A[], int n)
{
	int i; 
	struct Node *t,*last; // temp pointer
	Head = (struct Node*)malloc(sizeof(struct Node)); 
	Head->data = A[0]; //1st element 
	Head->next = Head;
	last = Head; 

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));// everytime creating new node 
		t->data = A[i]; 
		t->next = last->next; // linking since it is circular so it can not be NULL  // //here last->next is always the Head //everytime the newly created node will point to the Head node
		last->next = t; // last next will again come to 1st  // //previous node now links to the newly created node
		last = t; // //last pointer is updated on the newly create node
	}

}

void Display(struct Node* h)
{
	do
	{
		printf("->%d ", h->data);
		h = h->next;
	} while (h != Head);
	printf("\n");
}
// finding the length of CLL
int Length(struct Node* h) 
{
	int len = 0; // initializing length as zero 
	do {
		len++; // increatment everytime length by 1
		h = h->next; // move h to next
	} while (h != Head); // again when h comes on head terminate the loop
	return len; // return the length 

}
// inserting elements in CLL at a position and 1st and last // inserting before 1st will have cont time 

void Insert(struct Node* p, int pos, int x) // passing ll // passing pos at which we want to insert // data to be inserted 

{
	if (pos <0 || pos >Length(Head))
		return;
	struct Node* t;
	int i;
	if (pos == 0) // want to insert before Head node 
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		if (Head == NULL) // if there is no element in LL // that is head is alresy Null
		{
			Head = t;
			Head->next = Head;
		}
		else // if there is some node in p ;
		{
			p = Head;
			while (p->next != Head)
				p = p->next;
			p->next = t;
			t->next = Head;
			Head = t;
		}
			
		}
	else // index is not zero 
	{
		//p = Head; // take p upon head node 
		for (i = 0; i < pos - 1; i++) p = p->next;// move p for pos-1 time 
		t = (struct Node*)malloc(sizeof(struct Node));
			//struct Node* t; // creating new node for allocating the data 
		t->data = x; // set data to created node 
		t->next = p->next; // new created nodes next will point p next i.e linking 
		p->next = t; // set p next to t
	}

}
int main()
{
	int A[] = { 1,2,3,4,5,6,9 };
	Create(A, sizeof(A) / sizeof(int));

	Insert(Head, 6, 10);
	Display(Head);


	return 0;

}


