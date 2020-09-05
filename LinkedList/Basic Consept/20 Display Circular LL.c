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



int main()
{
	int A[] = { 1,2,3,4,5,6,9 };
	Create(A, sizeof (A)/sizeof(int));
	Display(Head);
	printf("\n");
	printf("%d", (Head->next->next->next->next->next->next->next)->data); // it proves that ll is circular // if we get the first element again it shows that ll is circular 
	printf("\n");
	Rdisplay(Head);


	return 0;

}
