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

void Levelorder(struct Node* root) // pass a root node  pointer 
{
	struct Queue q; // initialize queue // front rear everything will be intialized
	create(&q, 100); // all create fxn and create a larger queue to store the address of pointers // root ptr // lchild ptr // rchild ptr 
	printf("%d ", root->data); // print  data of root 
	enqueue(&q, root); // push addresh of root in the queue 
	// since we will perform operation on full so taking while loop iterating through tree  
	while (!isEmpty(q)) // when q is having some address of node // when queue is not empty
	{
		root = dequeue(&q); // pop out the adress of root from queue // and move to left child 
		if (root->lchild) // if left child of root/tree is there then
		{
			printf("%d ",root->lchild->data); // print the value of left child 
			enqueue(&q, root->lchild); // push the addresh of left child in queue  and move to right child 
		}
		if (root->rchild) // if right child is there in root/tree
		{
			printf("%d ", root->rchild->data); // print value of right child and 
			enqueue(&q, root->rchild); // push the address of right child in the queue 
		}
	}

}


int main()
{
	TreeCreate();
	Levelorder(root);

}
