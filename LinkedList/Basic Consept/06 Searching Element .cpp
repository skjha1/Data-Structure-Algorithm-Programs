#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*first =NULL;
void create(int a[], int n)
{
	int i;
	struct Node * t, * last;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = a[0];
	first->data = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;

	}
	
}
struct Node* Lsearch(struct Node* p, int key)
{
	while (p != NULL)
	{
		if (key == p->data)
			return p;
		p = p->next;
	}
	return NULL;
}
int main()
{
	struct Node* temp;
	int a[] = { 1,2,3,4,5,8,9,7 };
	create(a,9);
	temp = Lsearch(first, 9);
	if (temp)
	{
		printf("Key is found %d", temp->data);

	}
	else
		printf("Key not found !");
	return 0;

}