#include <stdio.h>
#include <stdlib.h>
struct Node // this is structure for bnary search tree 
{
	struct Node* lchild;
	int data;
	struct Node* rchild;
}*root = NULL;
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
struct Node* RInsert(struct Node* p, int key) // passing root pointer and the key element to be inserted  //  it is just like Rsearch function 
{
	struct Node* t = NULL; // a temp varibale initialized with null 
	if (p == NULL)
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // creating leaf node 
		t->data = key; // inside node data set the key's value 
		t->lchild = t->rchild = NULL; // set as null 
		return t; // t's set to the parent node 
	}
	if (key < p->data) // if val is less then root's  data 
		p->lchild = RInsert(p->lchild, key); // then insert value in left side // and store node in p->lchild  ;
	else if (key > p->data)
		p->rchild = RInsert(p->rchild, key); // call and take address in rchild
	// when key is equal  
	return p;  // we dont have to anything simply return p

}

int main()
{
	struct Node* temp;
	root =RInsert(root,10);
	RInsert(root,5);
	RInsert(root,20);
	RInsert(root,8);
	RInsert(root,30);

	Inorder(root);
	printf("\n");
	temp = Search(80);
	if (temp != NULL)
		printf("element %d is found \n", temp->data);
	else
		printf("Element is not found");
	return 0;
}
