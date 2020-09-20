#include <stdio.h>
#include <stdlib.h>
struct Node // this is tree node 
{
	struct Node* lchild; // lefe child as node in tree
	int data; // data element
	struct Node* rchild; // right child as node in tree 
};
// we are implementing tree with the help of queue 
struct Queue
{
	int size; // size of queue
	int front; // front of queue  // using for del
	int rear; // last of queue used for insertion 
	struct Node** Q; // this should be an aray of nodes
};
void create(struct Queue* q, int size) // creating a  queue // passing pointer and the size of queue 
{
	q->size = size;  // size of queue 
	q->front = 0; // make front and rear as null intially 
	q->rear = 0;
	q->Q = (struct Node**)malloc(q->size * sizeof(struct Node*)); // allocating space in heap 
}
void enqueue(struct Queue* q, struct Node* x)  // passing queue as pointer
{
	if ((q->rear + 1) % q->size == q->front) // checking wheather queue is full 
		printf("Queue if FULL");
	else
	{
		q->rear = (q->rear + 1) % q->size;
		q->Q[q->rear] = x; // push the data 
	}
}
struct Node* dequeue(struct Queue* q)
{
	struct Node* x = NULL;
	if (q->front == q->rear)
		return NULL;
	else
	{
		q->front = (q->front + 1) % q->size;
		x = q->Q[q->front];
		return x;
	}
}
int isEmpty(struct Queue q)
{
	return q.front == q.rear;
}
struct Node* root = NULL;
void TreeCreate()
{
	struct Node* t, * p;
	int x;// val of root
	struct Queue q;
	create(&q, 20); // size of a queue should be bigger
	root = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter a Root Value :\n");
	scanf_s("%d", &x);
	root->data = x; 
	root->lchild = NULL;
	root->rchild = NULL;
	enqueue(&q, root);
	while (!isEmpty(q))
	{
		p = dequeue(&q);
		printf("Enter Left Child of %d :", p->data);
		scanf_s("%d", &x);
		if (x != -1)

		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);
		}
		printf("Enter Right Child of %d:", p->data);
		scanf_s("%d", &x);
		if (x != -1)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q, t);
		}
	}

}
int rcount(struct Node* root)
{
	if (root)
		return count(root->lchild) + count(root->rchild) + 1;
	return 0;
}
int rheight(struct Node* root)
{
	int x = 0, y = 0;
	if (root == 0)
		return 0;
	x = height(root->lchild);
	y = height(root->rchild);
	if (x > y)
		return x + 1;
	else
		return y + 1;

}


int main()
{
	TreeCreate();
	printf("total node count is %d \n",rcount(root));
	printf("Height of Tree is %d ",rheight(root));

}
