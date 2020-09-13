#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int size;						//size for the fixed size array which is going to be the Queue
	int front;						//index pointer for deletion from Queue
	int rear;						//index pointer for insertion in Queue
	int* Q;							//pointer to create the Queue dynamically in the HEAP
};

void create(struct Queue* q, int size)
{
	q->size = size;											//size of array assigned
	q->front = q->rear = -1;								    //front and rear are initialised with 0 //it is done for Circular Queue in order to use Mod operations to achieve Circular Mechanism
	q->Q = (int*)malloc(q->size * sizeof(int));			//Array is created dynamically in HEAP of size equal to q->size
}

void enqueue(struct Queue* q, int x)						//Function to insert element in the Queue
{
	if ((q->rear + 1) % q->size == q->front)								//Condition to check Queue is full or not //This is the condition to achieve the circular mechanism for adopting Circular Queue
		printf("Queue is Full\n");
	else
	{
		q->rear = (q->rear + 1) % q->size;						//rear is assigned as (rear+1)%size //it is a mechanism to obtain circular and repeating values in the array //for circular queue
		q->Q[q->rear] = x;									//value is inserted in Q[rear]
	}
}

int dequeue(struct Queue* q)								//Function to delete element from the queue
{
	int x = -1;												//x will store the deleted value //initialised with -1 //if queue is empty the function will return -1

	if (q->front == q->rear)									//Condtion to check if Queue is empty or not //Queue is empty when front equals rear
		printf("Queue is Empty\n");
	else
	{
		q->front = (q->front + 1) % q->size;					//front is assigned as (front+1)%size //it is a mechanism to obtain circular and repeating values in the array //for circular queue
		x = q->Q[q->front];									//x is assigned with the value of Q[front]
	}
	return x;												//return x
}

void display(struct Queue q)
{
	int i = (q.front + 1) % q.size;								//Since, front points the index just before the first element, i should start from front+1 //rear points exactly to the previous element of front in a Circular Queue																

	do
	{
		printf("%d ", q.Q[i]);
		i = (i + 1) % q.size;										//i is incremented as (i+1)%size //algorithm to obtain circular and repeating values
	} while (i != (q.rear + 1) % q.size);								//Here, terminating condition of the do while loop is when i equals to (q.rear+1)%q.size //Since, it is a Circular Queue the terminating condition must follow the same mechanism of circularity

	printf("\n");
}

int main()
{
	struct Queue q;
	create(&q, 5);

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);

	//dequeue(&q);

	display(q);

	return 0;
}