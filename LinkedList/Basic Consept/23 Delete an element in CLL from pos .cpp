#include<iostream>
 
using namespace std;
 
 
 
struct Node
 
{
 
    int data;
 
    struct Node *next;
 
}*Head=NULL;
 
 
 
void Create(int A[100], int n)
 
{
 
    struct Node *t, *last=NULL;
 
    Head = new Node;
 
    Head->data = A[0];
 
    Head->next = last; // here it should be last
 
    last = Head;
 
 
 
    for(int i=1; i<n; i++)
 
    {
 
        t = new Node;
 
        t->data = A[i];
 
        t->next = Head; // here it should point to first node
 
        last->next = t;
 
        last = t;
 
    }
 
}
 
 
 
void Display(struct Node *h)
 
{
 
    do
 
    {
 
        cout<<h->data<<" ";
 
        h = h->next;
 
    }while(h != Head);
 
//    cout<<endl;
 
}
 
 
 
int Count(struct Node *p)
 
{
 
    int len = 0;
 
    do
 
    {
 
        len++;
 
        p = p->next;
 
    }while(p != Head);
 
 
 
    return len;
 
}
 
 
 
int Delete(struct Node *p, int index)
 
{
 
    struct Node *q;
 
    int i, x;
 
 
 
    if(index<0 || index>Count(p))
 
        return -1;
 
 
 
    if(index == 1)
 
    {
 
        while(p->next != Head)
 
            p = p->next;
 
 
 
        x = Head->data;
 
        if(p == Head)
 
        {
 
            delete Head;
 
            Head = NULL;
 
        }
 
        else
 
        {
 
            p->next = Head->next;
 
            delete Head;
 
            Head = p->next;
 
        }
 
    }
 
    else
 
    {
 
        for(i=0; i<index-2; i++)
 
            p = p->next;
 
        q = p->next;
 
        p->next = q->next;
 
        x = q->data;
 
        delete q;
 
    }
 
    return x;
 
}
 
 
 
int main()
 
{
 
    int n, i, A[100],x,pos;
 
    cout<<"Enter number of Nodes for Circular Linked List : ";
 
    cin>>n;
 
    cout<<"Enter all the Nodes of Circular Linked List : ";
 
    for(i=0; i<n; i++)
 
        cin>>A[i];
 
 
 
 
 
    Create(A,n);
 
    cout<<"Given Circular Linked List is : ";
 
    Display(Head);
 
 
 
    cout<<"Enter the position from which you want to delete a Node : ";
 
    cin>>pos;
 
    cout<<endl;
 
 
 
    x = Delete(Head,pos);
 
    cout<<"Circular Linked List after deleting "<<x<<" from position "<<pos<<" is : ";
 
    Display(Head);
 
 
 
    return 0;
 
}
