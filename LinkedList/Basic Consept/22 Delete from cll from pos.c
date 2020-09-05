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

void Rdisplay(struct  Node* h)
{
	static int flag = 0; // this static variable will let us know if hand Head are equal for the first time or the second time //it is used just for terminating the loop
	if (h != Head || flag == 0)  // 1st time flag will be zero so it enters in the cond and print the value // from second time 1st h!=Head will be true 
	{
		flag = 1;
		printf("->%d ", h->data);
		Rdisplay(h->next);
	}
	flag = 0;
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

int Delete(struct Node* p, int index) // pass head node , index to del 
{
	struct Node* q; // extra ptr
	int i, x; // traversing and storing 

	if (index <0 || index >Length(Head)) // if index is valid or not 
		return -1;
	if (index == 1) // if index is 1st index // then del head node 
	{
		while (p->next != Head)p = p->next; // traversing through ll in // moving p to last 
		x = Head->data; // store data from head ro x 
		if (Head == p) // is it the last node 
		{
			free(Head); // then free head 
			Head = NULL; // assign head as null
		}
		else // if it not the only node 
		{
			p->next = Head->next; // make p next on head next , so that head is logically re;ased 
			free(Head);// free it from heap memery 
			Head = p->next; // make head points on next of p
		}
	}
	else // it index is not 1 then the procedure is similar to lll
	{
		for (i = 0; i < index - 2; i++)
			p = p->next; // everytime move p to next 
		q = p->next;
		p->next = q->next;
		x = q->data;
		free(q);
	}
	return x;
}
int main()
{
	int n, i, x,pos;
	int A[100];
	printf("enter the no of nodes in ll ");
	scanf_s("%d",&n);
	printf("enter all nodes of cll ");
	for (i = 0; i < n; i++)
		scanf_s("%d", &A[i]);
	Create(A, 5);
	printf("Given Circular LL is ");
	Display(Head);

	printf("Enter the pos from which you want to del node ");
	scanf_s("%d", &pos);
	x= Delete(Head, pos);
	printf("Circular Linked List after deleting id %d from position  %d is \n ",x,pos);
	
	Display(Head);
	
	return 0;
}


/*
The scanf_s() function reads data from the standard input stream stdin and writes the
data into the location given by argument. Each argument must be a pointer to a variable 
of a type that corresponds to a type specifier in format. If copying takes place between 
strings that overlap, the behavior is undefined.*/
