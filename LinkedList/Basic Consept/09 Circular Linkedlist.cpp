#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;   // Self refrencial pointer
}*Head; // global pointer we will use it in entire program

void Create(int A[], int n)
{
	int i; // creating a varible for iteration 
	struct Node* t, * last; // t is for creating 1st node and last will always help in adding new noe at last 
	Head = (struct Node*)malloc(sizeof(struct Node)); // allocating memory in heap // create 1st node and make head point on that node 
	Head->data = A[0]; // passing data to 1st node 
	Head->next = Head;// Head will point on head itself so that it can form a circular linked list 
	last = Head;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // everytime we will create a new node with this 
		t->data = A[i]; // everytime assigning data from the array to linkedlist 
		t->next = last->next; // since it is circular so i acnnot use null here , this is linking new node next with last next (head)
		last->next = t; 
		last = t;

	}


}
void Display(struct Node* h) // This is for Displaying Normal 
{
	do
	{
		printf("->%d ", h->data);
		h = h->next;
	} while (h != Head);
	printf("\n");
}

void RDisplay(struct Node* h)
{
	static int flag = 0;
	if (h != Head || flag == 0)
	{
		flag = 1;
		printf("->%d ", h->data);
		RDisplay(h->next);
	}
	flag = 0;
	
}


int main()
{
	int A[] = { 2,3,4,5,6,7,89,98 };
	Create(A, sizeof (A)/sizeof (A[0]));
	Display(Head);
	RDisplay(Head);

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
