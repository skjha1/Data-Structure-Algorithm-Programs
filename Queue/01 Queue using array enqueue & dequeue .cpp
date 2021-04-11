// deletion will be always done from front 
// insertion will be always done from rear
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
	if (q->rear == q->size - 1) // condition for checking either queue is full or not 
		printf("queue is full");
	else // if queue is not full then we can insert element in queue 
	{
		q->rear++; // increatment the rear and then insert element 
		q->Q[q->rear] = x;// inserting element in the queue 
	}
}
int dequeue(struct Queue* q)
{
	int x = -1; // assign x with -1 intially 
	if (q->front == q->rear) // condition for checking the either queue is empty or not 
		printf("Queue is empty");
	else // if there is element in the queue 
	{
		q->front++; // increment the front and then take out the front element
		x=q->Q[q->front]; // store deleted element in the x 
	}
	return x; // and return it 
}
void Display(struct Queue q) // function for displaying queue 
{
	int i;
	for (i = q.front + 1; i <= q.rear; i++) // traversing the queue 
		printf("%d ",q.Q[i]); // and printing the eleemnt 
	printf("\n");
}
int main()
{
	struct Queue q; // making a queue objects in main funtion 
	Create(&q, 5); 
	enqueue(&q, 10);
	enqueue(&q, 15);
	enqueue(&q, 20);
	enqueue(&q, 30);
	Display(q);
	printf("%d ",dequeue(&q));
	return 0;
}
