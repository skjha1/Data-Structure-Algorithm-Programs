#include <stdio.h>
#include <stdlib.h>
struct Node // this is structure for bnary search tree 
{
	struct Node* lchild;
	int data;
	struct Node* rchild;
}*root=NULL;
void Insert(int key) // key value to be inserted 
{
	struct Node* t = root; // set a temp variable pointer to the root 
	struct Node* r, * p; // r will follow t // p for creating a new node 
	if (root == NULL)
	{
		p = (struct Node*)malloc(sizeof(struct Node)); // creating a new node in heap memory for inserting new data 
		p->data = key; // assign the p's data part with key value 
		p->lchild = p->rchild = NULL; // set left and right as null initilally
		root = p; // and again root should point on new node 
		return;
	}

		// now take a loop so that we can repeat the steps upto t becomes null so 
		while (t != NULL)
		{
			r = t;
			if (key < t->data)
				t = t->lchild; // move t upon left child 
			else if (key > t->data)
				t = t->rchild; // move t upon right child 
			else
				return;

		}
		// creating node for insering element
		p = (struct Node*)malloc(sizeof(struct Node)); // creating a new node in heap memory for inserting new data 
		p->data = key; // assign the p's data part with key value 
		p->lchild = p->rchild = NULL; // set left and right as null
		// linking node to existing tree 
		if (key < r->data)
			r->lchild = p; // linking newly created node as left child of tree
		else
			r->rchild = p;// linking newly created node as right child of tree
	

}
// function for inorder traversal 
void Inorder(struct Node* p)
{
	if (p != NULL)
	{
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}
struct Node* Search(int key)
{
	struct Node* t = root;
	while (t != NULL)
	{
		if (key == t->data)
			return t;
		else if (key < t->data)
			t = t->lchild;
		else
			t = t->rchild;
	}
	return NULL;
}
int main()
{
	struct Node* temp;
	Insert(10);
	Insert(5);
	Insert(20);
	Insert(8);
	Insert(30);

	Inorder(root);
	printf("\n");
	temp = Search(80);
	if (temp != NULL)
		printf("element %d is found \n", temp->data);
	else
		printf("Element is not found");
	return 0;
}
