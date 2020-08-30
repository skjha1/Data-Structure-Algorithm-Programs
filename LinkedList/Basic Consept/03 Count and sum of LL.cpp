//Count and Sum Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
int count(struct Node *p)
{
 int l=0;
 while(p)
 {
 l++;
 p=p->next;
 }
 return l;
}
int Rcount(struct Node *p)
{
 if(p!=NULL)
 return Rcount(p->next)+1;
 else
 return 0;
}
int sum(struct Node *p)
{
 int s=0;

 while(p!=NULL)
 {
 s+=p->data;
 p=p->next;
 }
 return s;
}
int Rsum(struct Node *p)
{
 if(p==NULL)
 return 0;
 else
 return Rsum(p->next)+p->data;
}
int main()
{
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);

 printf("Count %d\n",count(first));
 printf("Sum %d\n",sum(first));



 return 0;
}
