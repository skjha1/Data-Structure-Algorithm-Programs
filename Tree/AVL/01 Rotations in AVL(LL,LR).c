#include<stdio.h>
#include<stdlib.h>
struct Node // defining a structure noe for AVL tree 
{
	struct Node* lchild;  // left poither for tree node 
	int data; // data to be passed 
	int height; // height of the tree 
	struct Node* rchild; // right pointer for tree node 
}*root=NULL; // global pointer can be passed as perimeter throughout the program 

// Now we have to perform insert so make a recursive function for inserting that fxn sud be of struct Type 

int NodeHeight(struct Node* p) // fxn for finding height 
{
	int hl, hr; // height of left-sub-tree & right-sub-tree
	hl = p  /* it sud not be null */ && p->lchild ? p->lchild->height : 0; // p sud not be null as well if p's left child is sud be there then take the height of the p's left child else if it is not  take  as zero 
	// same repat for right child 
	hr = p && p->rchild ? p->rchild->height : 0;

	return hl > hr ? hl + 1 : hr + 1; // whichever is greater in that add 1 and set the height of p ; // if hl is greter than hr then return hl+1 else hr+1;

}

int BalanceFactor(struct Node* p) // function for finding Balance factor 
{
	// balance factor is (height-of-left-sub-tree - height-of-right-sub-tree)
	int hl, hr;
	hl = p && p->lchild ? p->lchild->height : 0;
	hr = p && p->rchild ? p->rchild->height : 0;
	return hl - hr;  // returing balance factor 
}
struct Node* LLRotation(struct Node* p) // this fxn is for left-left rotation // 
{
	struct Node* pl = p->lchild; // take ptr pl that will be root left node 
	struct Node* plr = pl->rchild; // this will be root left's right node 
	// make changes for rotation 
	pl->rchild = p;  // p's left right child make as p 
	p->lchild = plr; // p's left child make it as plr 
	p->height = NodeHeight(p); // modify the height of p after rotation 
	pl->height = NodeHeight(pl); // modify the height of pl after rotation 

	if (root == p) // if root and p is equal 
		root = pl; // then root should be change to pl 

	return pl; // and then return pl as new root 
}
struct Node* LRRotation(struct Node* p)
{
	struct Node* pl = p->lchild;
	struct Node* plr = pl->rchild;

	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;
	// make changes i.e appaly LR Rotation 
	plr->lchild = pl;
	plr->rchild = p;
	//  modify height 
	pl->height = NodeHeight(pl);
	p->height = NodeHeight(p);
	plr->height = NodeHeight(plr);

	if (root == p)
		root = plr;
	return plr;
}
struct Node* RRRotation(struct Node* p)
{
	return NULL;
}
struct Node* RLRotation(struct Node* p)
{
	return NULL;
}

struct Node* RInsert(struct Node* p, int key) // passing a pointer to the root node and the value to be inserted 
{
	struct Node* t = NULL;
	
	if (p == NULL)
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // making a node space in heap memory 
		t->data = key; // assigning data to that node 
		t->height = 1; // here we are starting height of tree from 1 onwards 
		t->lchild = t->rchild = NULL; // initially keep that node left and right ptr as zero 
		return t; 
	}
	if (key < p->data)
		p->lchild = RInsert(p->lchild,key); // recursion call 
	else if (key > p->data)
		p->rchild = RInsert(p->rchild, key); // recursion call for right 

	// at the time of returning update the height whicheb=ver is greater take that height 
	p->height = NodeHeight(p); // here the max height is stored 
	if (BalanceFactor(p) == 2 && BalanceFactor(p -> lchild) == 1) 
		return LLRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p -> lchild) == -1)
		return LRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p -> rchild) == -1)
		return RRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p -> rchild) == 1)
		return RLRotation(p);
	return p;
}

int main()
{
	root = RInsert(root, 10);
	RInsert(root, 5);
	RInsert(root, 2);



	return 0;
}
