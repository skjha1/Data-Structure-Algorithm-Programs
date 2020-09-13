
#include<iostream>
using namespace std;

class Stack
{
public:
	int top;
	int size;
	int* Q;
	bool isEmpty();
	bool isFull();
	void push(int x);
	int pop();
	void display();
};

bool Stack::isEmpty()
{
	if (top == -1)
		return true;
	return false;
}

bool Stack::isFull()
{
	if (top == size - 1)
		return true;
	return false;
}

void Stack::push(int x)
{
	if (isFull())
		cout << "Stack Overflow" << endl;
	else
	{
		top++;
		Q[top] = x;
	}
}

int Stack::pop()
{
	int x = -1;
	if (isEmpty())
		cout << "Stack Underflow" << endl;
	else
	{
		x = Q[top];
		top--;
	}
	return x;
}

void Stack::display()
{
	int i;
	for (i = 0; i <= top; i++)
		cout << Q[i] << " ";
	cout << " ";
}

class Queue
{
private:
	Stack s1;
	Stack s2;
public:
	Queue(int size);
	~Queue();
	void enqueue(int x);
	int dequeue();
	void Display();
};

Queue::Queue(int size)
{
	s1.top = -1;
	s2.top = -1;

	s1.size = size;
	s2.size = size;

	s1.Q = new int[size];
	s2.Q = new int[size];
}

Queue::~Queue()
{
	delete[] s1.Q;
	delete[] s2.Q;
}

void Queue::enqueue(int x)
{
	s1.push(x);
}

int Queue::dequeue()
{
	int x = -1;
	if (s2.isEmpty())
	{
		if (s1.isEmpty())
		{
			cout << "Both Queue underflow" << endl;
			return x;
		}
		else
		{
			while (!s1.isEmpty())
			{
				s2.push(s1.pop());
			}
		}
	}
	x = s2.pop();
	return x;
}

void Queue::Display()
{
	s1.display();
	s2.display();
}

int main()
{
	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);

	q.dequeue();

	q.Display();
}