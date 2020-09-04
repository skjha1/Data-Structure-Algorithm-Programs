
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

// Remove duplicate from ll ; if nodes data are same del that ; from sorted linkedlist 
void Removeduplicate(struct Node* p) // taking pointer to 1st node 
{
	// inside fxn we want  one more pointer 
	struct Node* q = p->next; // which will before p  // q is ahead and p is following 
	while (q != NULL)
	{
		if (p->data != q->data) // if data is not matching  // means no duplicate 
		{
			p = q; // move ahead 
			q = q->next;
		}
		else // if there is duplicate value 
		{
			p->next = q->next;  // p next points on  q next //q will be logically remove from ll 
			free(q); // delete q 
			q = p->next; // and move q to next  
		}
	}
}




int main()
{
	int A[] = {10,10,10,10,20,20,20,30,40,50 };
	Create(A, sizeof (A)/sizeof (int ));
	Removeduplicate(first);
		Display(first);
		printf("\n\n");

	return 0;

}
