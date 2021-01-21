#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
}*first;

void Create(int A[], int no)
{
	int i;
	struct Node* t, * last;
	first = new Node;

	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < no; i++)
	{
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}

}

void Display(struct Node* p)
{
	while (p != NULL)
	{
		cout << p->data << "->";
		p = p->next;
	}
}

void RDisplay(struct Node* p)
{
	if (p != NULL)
	{
		
		cout << p->data << "->";
		RDisplay(p->next); // for reverse call 1st then print 
	}
}

int Count(struct Node* p)
{
	int c=0;
	while (p != NULL)
	{
		c++;
		p = p->next;
		
	}
	return c;
}

int Rcount(struct Node* p)
{
	if (p != NULL)
		return Rcount(p->next) + 1;
	else
		return 0;
}

int Sum(struct Node* p)
{
	int sum = 0;
	while (p!=0)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int Rsum(struct Node* p)
{
	if (p == 0)
		return 0;
	return Rsum(p->next) + p->data;
}

int main()
{
	int A[] = { 1,2,3,4,5 };
	int no = sizeof(A) / sizeof(int);
	Create(A, no);
	RDisplay(first);
	cout << endl;

	cout << "Total terms in the LL is " << Count(first)<<endl;
	cout << "Total sum of the LL is " << Sum(first)<<endl;
	cout << "Revursive count " << Rcount(first)<<endl;
	cout << "Recursive sum is " << Rsum(first) << endl;
	return 0;
}
