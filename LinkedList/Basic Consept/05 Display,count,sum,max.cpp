#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
}*first = NULL;					//Global Pointer //Can be directly accessed and can pass as parameter

void create(int A[], int n)
{
	int i;
	struct Node* t;				//temporary node help in creating new node
	struct Node* last;			//pointer to point at last node //helps in adding new node in end of linked list

	first = (struct Node*)malloc(sizeof(struct Node));        //creates space for first node in heap
	first->data = A[0];										  //data part is assigned as first element of the array
	first->next = NULL;										  //next pointer points to NULL only
	last = first;										     //last pointer made to point at first node //helps in linking nodes [V. Imp]

	for (i = 1; i < n; i++)										//starting from 1 as already 0th element is created
	{
		t = (struct Node*)malloc(sizeof(struct Node));     //everytime a new space is created in heap for a new node represented by t
		t->data = A[i];										//data part is assigned according to array element
		t->next = NULL;										//everytime the node is created its next points to NULL as there is no node after that
		last->next = t;										//helps in linking the previous node with the newly created node
		last = t;											//last refreshes its pointer to the newly created node that will help again in linking a newly created node in next iteration
	}

}

void display(struct Node* p)
{
	while (p != NULL)
	{
		printf("%d-> ", p->data);
		p = p->next;
	}
	printf("0");
}

void RDisplay(struct Node* p)
{
	if (p != NULL)
	{
		printf("%d-> ", p->data); // here first print then call // we can call first and then print also 
		RDisplay(p->next);
		//printf("0");
	}
	
	
}

void R1Display(struct Node* p)
{
	if (p != NULL)
	{
		 
		R1Display(p->next); // first call then print 
		printf("%d-> ", p->data);
	}
	//printf("0");

}

int count(struct Node *p)
{
 int l=0;
 while(p)
 {
 l++;
 p=p->next;
 }
 return l;
}
int Rcount(struct Node* p)
{
	if (p != NULL)
		return Rcount(p->next) + 1;
	else
		return 0;
}

int sum(struct Node* p)
{
	int sum = 0;
	while (p)
	{
		sum = sum + p->data;
		p = p->next;
	}
	return (sum);
}
int Rsum(struct Node* p)
{
	if (p == 0) return 0;
	else return Rsum(p->next) + p->data;
}

int Max(struct Node* p)
{
	int max = INT_MIN; // int_min is the minumum value associated with integer

	while (p)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;

}
int Rmax(struct Node* p)
{
	int x = 0;
	if (p == 0)
		return INT_MIN;
	else {
		x = Rmax(p->next);
		if (x > p->data)
			return x;
		else
			return p->data;
	}
}
int main()
{
	int A[] = { 3,5,6,7,100,15 ,98};

	create(A, sizeof(A) / sizeof(int));
	printf("Displying linked list using iteration \n\n");
	display(first);
	printf("\nLinked list using recursion\n\n");
	RDisplay(first);
	printf("\nLinked list using recursion where 1st calling and then printing \n\n");
	R1Display(first);
	printf("\nCount using iteraion  %d\n\n", count(first));
	printf("Count using recursion  %d\n\n", Rcount(first));
	printf("\nsum of the linkedlist is %d\n\n", sum(first));
	printf("\nsum using recursion %d\n\n", Rsum(first));
	printf("\nmaximum of the linkedlist is %d\n\n",Max(first));
	printf("\nmaximum of the linkedlist using recursion is %d\n\n", Rmax(first));
	
	//display(first);

	return 0;
}