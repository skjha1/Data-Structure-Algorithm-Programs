/* Code written 
	@author Shivendra k jha  
	some singly linkedlist code like create , display , max , sum , count, searching, insertion   using normal method and using recursion 

*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*first=NULL;
void Create(int A[], int n)
{
	int i;
	struct Node* last, * t;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
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
		printf("->%d", p->data);
		p = p->next;
	}
}
void RDisplay(struct Node* p)
{
	if (p!=NULL)
	{
		printf("->%d", p->data);
		RDisplay(p->next);
	}
}

int count(struct Node* p)
{
	int c = 0;
	while (p != NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}
int Rcount(struct Node* p)
{
		if (p == 0) return 0;
		else
			return Rcount(p->next) + 1;
	
}
int sum(struct Node* p)
{
	int sum = 0;
	while (p != NULL)
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
	else
		return Rsum(p->next) + p->data;
}

int max(struct Node* p)
{
	int m = -3276;
	while (p != NULL)
	{
		if (m < p->data)
			m = p->data;
		p = p->next;
	}
	return m;
}
int max1(struct Node* p)
{
	int x = 0;
	if (p == 0)
		return INT_MIN;
	else {
		x = max1(p->next);

		if (x > p->data)
			return x;
		else return p->data;
			
	}
}
int Rmax(struct Node* p)
{
	int x = 0;
	if (p == 0)
	{
		return INT_MIN;
	}
	else
		x=Rmax(p->next);
	return x > p->data ? x : p->data; // using ternary operator
}

// Binary search is not possible in linkedlist // Binery search is only for sorted array 

struct Node* LSearch(struct Node* p, int key)
{
	struct Node* q=NULL;

	while (p != NULL)
	{
		if (key == p->data)
		{
			return p;
			p = p->next;
		}
		
		p = p->next;
	}
	return NULL;

}

struct Node* RSearch(struct Node* p, int key) // using recursion searching the  elements in linkes list 
{
	if (p == NULL)
		return NULL;
	if (key == p->data)
		return p;
	return RSearch(p->next, key);

}

//move to top approch 
struct Node* Movetotop(struct Node* p, int key)
{
	// for sending key element to top we need one extrea pointer i.e q
	struct Node* q=NULL;

	while (p != NULL)
	{
		if (p->data == key)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;

	}
	return NULL;
}

// Inserting in linkedlist // in array we start index from 0 ll is independent of that 
// we can insert by two pos 
// Insert before first & insert after given position 

void Insert(int pos, int x) // position at which element will be inserted and data (x) to be inserted
{
	struct Node* t, * p; // creating node 
	if (pos == 0) // before 1st node 
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // creating node memory in heap 
		t->data = x;   // data insertion on newly created node 
		t->next = first; // newly created first next (pointer) points to the old first (for linking purpose)
		first = t;   // Bring 1st on new node 
	}
	else if (pos > 0)
	{
		p = first;
		for (int i = 0; i < pos - 1 && p; i++)
			p = p->next;
		if (p)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->next = p->next;
			p->next = t;
		}
	}
}

// Insert at last 
void Insertlast(int y)
{
	struct Node* tt;
	struct Node* last;
	tt = (struct Node* )malloc (sizeof(struct Node));
	last= (struct Node*)malloc(sizeof(struct Node));
	tt->data = y; // assigning data to node  
	tt->next = NULL; // assigning node next with NUll 
	if (first == NULL)  // if the ll is alredy empty 
	{
		first = last = tt;
	}
	else
	{
		last->next = tt;
		last = tt;
	}


}

void Sortedinsert(struct Node* p, int x)
{
	struct Node* t, * q = NULL;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;/* first node is ready*/
	t->next = NULL; 
	if (first == NULL)
	{
		first = t;
	}
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}
}



int main()
{
	int a[] = { 2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,2,55,999 };
	int b[] = { 10,20,30,40,50 };
	Create(b, sizeof(b) / sizeof(int));
	Create(a, sizeof(a) / sizeof(int));
	struct Node* temp;
	Display(first);
	printf("\n Display using Recursion\n");
	RDisplay(first);
	printf("\nThe nodes in linkedlist is %d",count(first));
	printf("\nThe nodes in linkedlist using Recursion is %d", Rcount(first)); // size and space is o(n)
	printf("\nSum of the linkedlist is = %d", sum(first));
	printf("\nSum of LL using Recursion is = %d", Rsum(first));
	printf("\nMax in the linked list is %d", max(first));
	printf("\nmax in ll using another method %d", max1(first));
	printf("\nmax using recursion %d", Rmax(first));
	temp = LSearch(first, 888);
	if (temp)
		printf("\nData is found in ll using Linear search i.e : %d", temp->data);
	else
		printf("\nData is not Found ");
	temp = RSearch(first, 5);
	if (temp)
		printf("\nData is found in ll using Recursive method i.e : %d", temp->data);
	else
		printf("\nData is not Found");
	temp = Movetotop(first, 8); // this is for checking either that element is presnt or not 
	if (temp)
		printf("\ndata is found in ll i.e % d  and key element is moved to first position\n", temp->data);
	else
		printf("Element is not present\n");
	Display(first); // it will display after shifting to 1st position
	printf("\n");
	Insert(0, 666);// this is for inserting element in the ll( pos , data ) // o(n)
	Insert(1, 3);
	Insert(2, 4);
	Insert(3, 4); 
	Display(first); // Displaying after insertion 
	//imp //Display(first); // We can Create a new linked list with insertion method after removing array and create line in main code 
	printf("\n");
	Insertlast(28); // inserting at last 
	Display(first);
	printf("\n");
	Sortedinsert(first, 35); // this is for inserting in a sorted linked list i.e in create array b [] in main 
	Display(first);

	return 0;

}
