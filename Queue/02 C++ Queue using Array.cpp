#include<iostream>
#include<stdlib.h>
using namespace std;

class Queue
{
private:
	int front;
	int rear;
	int size;
	int* Q;
public:
	Queue()									//Non-parameterized constructor //front and rear are assigned as -1 //indicates Queue is empty
	{
		front = rear = -1;
		size = 10;							//Default size of the Queue will be 10
		Q = new int[size];					//Memory is allocated for the Queue in the HEAP
	}
	Queue(int size)							//Parameterized constructor with size as the parameter
	{
		front = rear = -1;
		this->size = size;
		Q = new int[this->size];
	}
	void enqueue(int x);
	int dequeue();
	void display();
};

void Queue::enqueue(int x)
{
	if (rear == size - 1)
		cout << "Queue is Full" << endl;
	else
	{
		rear++;
		Q[rear] = x;
	}
}

int Queue::dequeue()
{
	int x = -1;
	if (front == rear)
		cout << "Queue is Empty" << endl;
	else
	{
		front++;
		x = Q[front];
	}
	return x;
}

void Queue::display()
{
	int i;
	for (i = front + 1; i <= rear; i++)
		cout << Q[i] << " ";
	cout << endl;
}

int main()
{
	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);

	q.display();
	q.dequeue();
	q.display();

	return 0;
}