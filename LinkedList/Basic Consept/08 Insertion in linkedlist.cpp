#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

}*first=NULL;

void Create(int a[], int n)
{
    int i;
    struct Node* t, * last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
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

void Display(struct Node* p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void insert(struct Node *p , int pos, int x) // creating positioin and the value to be inserted 
{
    struct Node* t; // intializing node first
    if (pos == 0)
    {
        t = (struct Node*)malloc(sizeof(struct Node)); // Creating new node to enter value 
        t->data = x; // Inserting Data to the node 
        t->next = first; // points to first 
        first = t; //  Bringing 1st on the new node 
    }
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++) // i shoud be position -1 and weather p is pointing on any node or not 
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

int main()
{
    int a[] = { 1,2,4,5,7,4,5,44 };
    Create(a, 8);
    insert(first, 0, 5);
    Display(first);
    return 0;
}