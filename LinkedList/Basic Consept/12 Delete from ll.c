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
int count(struct Node* p) // pointer to 1st node 
{
	int c = 0; // intially assigning count as zero 
	while (p != NULL) // when ll is not empty
	{
		c++; // increase the no of count 1 everytime 
		p = p->next; // p to next node 
	}
	return c; // return the total nodes in ll 
}


int Delete(struct Node* p, int index) // it should take pointer to 1st node & index from which element to be deleted 
{
	struct Node* q=NULL; // tail pointer 
	int x = -1, i;

	if (index < 1 || index > count(p)) // weather index is valid or not , index is from 1 to length 
		return -1;
	if (index == 1) // special cse if index is on 1st node 
	{
		q = first; // make q points on 1st node 
		x = first->data; // take the data from 1st node 
		first = first->next; // move 1st pointer to next node 
		free(q); // del the previous 1st node 
		return x;
	}
	else // if it is not 1st index || any other index  
	{
		for (i = 0; i < index - 1; i++) // using for loop we will move p and q
		{
			q = p; // everytime q will moved upon p and p will move upon next node 
			p = p->next;
		} 
		// p will be pointing on node which we want to delete 
		q->next = p->next; // p will be logically removed from ll 
		x = p->data; // strote data to be del in x from p-data 
		free(p); // 
		return x; // deleted valte 

	}


}



int main()
{
	int A[] = { 10,20,30,40,50 };
	Create(A, 5);

	printf("The deleted element is %d\n", Delete(first, 5)); // we will pass invalid index it will show -1 
		Display(first);
		printf("\n\n");

	return 0;

}
