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

int Height(struct Node* p) // finding height of BST // take node to root node 
{
	int x, y;
	if (p == NULL) // if there is no node 
		return 0;
	x = Height(p->lchild); // x is height of p's left child 
	y = Height(p->rchild);// y is height of p's right child
	return x > y ? x + 1 : y + 1; // return whichever is greated either x or y 
}

struct Node* Inpre(struct Node* p) // passing root node // it sud return node typr 
{
	while (p && p->rchild != NULL) // it will go until rightmost child 
		p = p->rchild; // moving on right most child 

	return p;
}


struct Node* InSucc(struct Node* p)
{
	while (p && p->lchild != NULL) // it will go until leftmost child 
		p = p->lchild; // everytime move p ; 

	return p;
}


struct Node* Delete(struct Node* p, int key) // parameter as struct node p as root // and int key we want to del
{
	struct Node* q;

	if (p == NULL) // if there is no root 
		return NULL;
	if (p->lchild == NULL && p->rchild == NULL) // if it is a leaf node directly del the node 
	{
		if (p == root) //  if is root node  
			root = NULL; // root sud be null
		free(p); // del p  
		return NULL; // return NULL 
	}
	if (key < p->data) // if key is less then roots data 
		p->lchild = Delete(p->lchild, key); // perform search on LHS
	else if (key > p->data) // key is greater thrn p's data 
		p->rchild = Delete(p->rchild, key); // we will continue on RHS
	else // if key is found // then for deleting a key 
	{
		// here we have to find Inorder precedessor and Inorder successor 
		// if the height of the left subtree is more then we will del an element from left hand side 
		if (Height(p->lchild) > Height(p->rchild)) // if height is more then we will perform operation on left handside else from RHS if equal wecan del either side 
		{
			// here we  need inorder precedessor to del the element
			q = Inpre(p->lchild); // inpre of left subtree
			p->data = q->data; // now p's data i.e root data sud be changed with q's data 
			p->lchild = Delete(p->lchild, q->data); // after replacing delete the data // while del we have to modify more then one link 
		}
		else {
			// here we  need inorder successor ssor to del the element
			q = InSucc(p->rchild); // inpre of left subtree
			p->data = q->data; // now p's data i.e root data sud be changed with q's data 
			p->rchild = Delete(p->rchild, q->data); // after replacing delete the data // while del we have to modify more then one link 
		}

	}
	return p;
}

int main()
{
	struct Node* temp;
	root =RInsert(root,10);
	RInsert(root,5);
	RInsert(root,20);
	RInsert(root,8);
	RInsert(root,30);

	Delete(root, 10);

	Inorder(root);
	printf("\n");
	temp = Search(80);
	if (temp != NULL)
		printf("element %d is found \n", temp->data);
	else
		printf("Element is not found");
	return 0;
}
