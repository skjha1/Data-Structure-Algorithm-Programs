#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
}*front = NULL, * rear = NULL;										//front and rear pointer to help in insertion and deletion of nodes in Queue

void enqueue(int x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));					//Node is created in Heap

	if (t == NULL)													//if node was not created due to insufficient space in the HEAP
		printf("Queue is Full\n");
	else
	{
		t->data = x;
		t->next = NULL;

		if (front == NULL)											//if front is NULL it means it is the first node of the queue //first node condition
			front = rear = t;										//if it is the first node make front and rear both point on the first node
		else														//if it is not the first node
		{
			rear->next = t;											//last node which is rear //rear->next points on the new node
			rear = t;												//the new node is updated as the rear 
		}
	}
}

int dequeue()
{
	int x = -1;												//If Queue is empty the function will return -1 
	struct Node* t;											//temporary pointer to hold the address of the node that is to be deleted

	if (front == NULL)										//If front is NULL there is no nodes in the Queue
		printf("Queue is Empty\n");
	else
	{
		t = front;											//temp pointer is made to point on the front node
		front = front->next;								//front node is updated to its next node
		x = t->data;										//x assigns the data value of t node
		free(t);											//t node is deleted
	}
	return x;												//x is returned as the deleted element
}

void display()
{
	struct Node* p;
	p = front;

	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);

	display();

	dequeue();
	display(); // display after deltion 


	return 0;
}