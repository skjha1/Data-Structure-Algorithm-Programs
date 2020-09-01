/*Linked List  Implementati
Insertion at beginning-SLL
Add a node at the front: 
The new node is always added before the head of the given Linked List. And newly added node becomes the new head of the Linked List. For example if the current Linked List is 10->15->20->25 and we add an item 5 at the front, then the Linked List becomes 5->10->15->20->25. Let us call the function that adds at the front of the list is push(). The push() must receive a pointer to the head pointer, because push must change the head pointer to point to the new node
INPUT
First line contains the number of datas- N. Second line contains N integers(i.e, the datas to be inserted).
OUTPUT
Display the final Linked List.
7
1 2 3 4 8 1 0
Linked List
->0->1->8->4->3->2->1
2
6 3
Linked List
->3->6
4
8 6 1 4
Linked List
->4->1->6->8

code by @ shivendra k Jha */

#include <stdio.h>
#include <stdlib.h>
struct Node 
{
	int data ;
	struct Node *next;
	
}*first=NULL;
void insertion (int a)
{
	struct Node *temp= malloc (sizeof (struct Node ));
	temp->data=a;
	temp->next=NULL;
	
	if (first ==NULL)
	first=temp;
	else 
	{
		temp->next=first;
		first=temp;
		
	}
}


int main ()
{
	int a,n,i;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&a);
	insertion(a);
	}
	printf("Linked List\n");
  struct Node *temp = first;
  while(temp != NULL)
  {
    printf("->%d",temp->data);
    temp = temp ->next;
  }
	
	return 0;
}
