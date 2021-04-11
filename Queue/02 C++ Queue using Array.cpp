#include<iostream>
#include<stdlib.h>
using namespace std;

class Queue
{
private:
	int front; // front is used for deletion 
	int rear; // rear is used for insertion
	int size; // size of the queue 
	int* Q; // dynamically allocated space for queue 
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
	void enqueue(int x); // declaration for insertion element in the queue 
	int dequeue(); // declaration for deletion of the element queue 
	void display(); // declaration for displaying the queue 
};

void Queue::enqueue(int x) // passing the value as parameter for insertion 
{
	if (rear == size - 1)  // condition for checking queuefull 
		cout << "Queue is Full" << endl;
	else
	{
		rear++; // increament the rear and then insert the value in the queue
		Q[rear] = x; // insertion of the element.
	}
}

int Queue::dequeue()
{
	int x = -1; // initially set the value of the x to -1; setting 
	if (front == rear) // condition for cheking the queue empty 
		cout << "Queue is Empty" << endl;
	else
	{
		front++; // increment the front and take out the element 
		x = Q[front];
	}
	return x; // return the deleted value 
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
	Queue q(5); // Creating an instance for class and setting the size as 5 

	q.enqueue(10); // inserting the value in queue 
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);

	q.display(); // displaying queue 
	q.dequeue(); // deleting the value from the queue.
	q.display(); // then displaying it after deletion 

	return 0;
}
