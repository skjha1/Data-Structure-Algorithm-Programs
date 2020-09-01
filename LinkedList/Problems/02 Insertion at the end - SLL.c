/*Insertion at end-SLL
Add a node at the end: 
The new node is always added after the last node of the given Linked List. For example if the given Linked List is 5->10->15->20->25 and we add an item 30 at the end, then the Linked List becomes 5->10->15->20->25->30.
Since a Linked List is typically represented by the head of it, we have to traverse the list till end and then change the next of last node to new node.
INPUT
First line contains the number of datas- N. Second line contains N integers(i.e, the datas to be inserted).
OUTPUT
Display the final Linked List.
4
8 1 2 9
Linked List
->8->1->2->9
5
4 1 6 2 94
Linked List
->4->1->6->2->94
3
65 12 5
Linked List
->65->12->5

Code by @ shivendra kumar jha 

*/

#include <stdio.h>
#include <stdlib.h>
struct Node 
{
	int data ;
	struct Node *next;
}*first =NULL;
void display (struct Node *p)
{
	while (p!=NULL)
	{
		printf("->%d",p->data);
		p=p->next;
	}
}
 
struct Node *insert(struct Node *first ,int data)
{
	struct Node *nn=(struct Node *)malloc(sizeof(struct Node));
  nn->data=data;
  
  if(first==NULL)
  {
    nn->next=NULL;
    first=nn;
  }
  
  else
  {
    struct Node *p=first;
    while(p->next!=NULL)p=p->next;
    
    p->next=nn;
    nn->next=NULL;
  }
  
  return first;
}

int main()
{
  int size,i;
  scanf("%d",&size);
  int a[size];
  for(i=0;i<size;i++)scanf("%d",&a[i]);
  
  for(i=0;i<size;i++)first=insert(first,a[i]);
  
  printf("Linked List\n");
  display(first);

	return 0;
}

