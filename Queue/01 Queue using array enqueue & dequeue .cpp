#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int size; // size of queue
	int front; // front of queue // del is done from front
	int rear; // last of queue // indertion is donr from rear
	int* Q; // dynamically creatng Array 
};

void Create(struct Queue* q, int size)
{
	q->size = size;
	q->front = q->rear = -1; // initially queue is empty
	q->Q = (int*)malloc(q->size * sizeof(int)); // everytime taking creating in heap memory

}
void enqueue(struct Queue* q, int x)
{
	if (q->rear == q->size - 1)
		printf("queue is full");
	else
	{
		q->rear++;
		q->Q[q->rear] = x;
	}
}
int dequeue(struct Queue* q)
{
	int x = -1;
	if (q->front == q->rear)
		printf("Queue is empty");
	else
	{
		q->front++;
		x=q->Q[q->front];
	}
	return x;
}
void Display(struct Queue q)
{
	int i;
	for (i = q.front + 1; i <= q.rear; i++)
		printf("%d ",q.Q[i]);
	printf("\n");
}
int main()
{
	struct Queue q;
	Create(&q, 5);
	enqueue(&q, 10);
	enqueue(&q, 15);
	enqueue(&q, 20);
	enqueue(&q, 30);
	Display(q);
	printf("%d ",dequeue(&q));
	return 0;
}