/* Make a tree and print the largest value of the tree.

The first line of input contains a variable 'T'. Next 'T' lines contain the values of tree nodes. 

Output contains the largest element of the tree.
15
31
5
21
42
8
68
24
6
7
23
25
1
69
4
100
How many numbers do you want to insert ?
Largest number:100
6
5
6
4
1
2
3
How many numbers do you want to insert ?
Largest number:6
10
14
20
15
10
8
16
11
7
2
1
6
How many numbers do you want to insert ?
Largest number:20
*/

#include <stdio.h>
#include<stdlib.h>
 #include<iostream>
using namespace std;
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node 
with the given data and NULL left and right 
pointers. */
struct node* newNode(int data) 
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data  = data;
  node->left  = NULL;
  node->right = NULL;
   
  return(node);
}
 
/* Give a binary search tree and a number, 
inserts a new node with the given number in 
the correct place in the tree. Returns the new 
root pointer which the caller should then use 
(the standard trick to avoid using reference 
parameters). */
struct node* insert(struct node* node, int data) 
{
  /* 1. If the tree is empty, return a new,     
      single node */
  if (node == NULL) 
    return(newNode(data));  
  else
  {
    /* 2. Otherwise, recur down the tree */
    if (data <= node->data) 
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
   
    /* return the (unchanged) node pointer */
    return node; 
  }
}
 
/* Given a non-empty binary search tree,  
return the minimum data value found in that 
tree. Note that the entire tree does not need 
to be searched. */
int minValue(struct node* node) {
  struct node* current = node;
 
  /* loop down to find the leftmost leaf */
  while (current->right != NULL) {
    current = current->right;
  }
  return(current->data);
}
 
/* Driver program to test sameTree function*/   
int main()
{
  struct node* root = NULL;
  int n,a;
  cout<<"How many numbers do you want to insert ?"<<endl;
  cin>>n;
  int i;
  for(i=0;i<n;i++)
  {
    if(i==0)
    {
      cin>>a;
      root=insert(root,a);
    }
    else
    {
      cin>>a;
      insert(root,a);
    }
  }
  printf("Largest number:%d", minValue(root));
  getchar();
  return 0;    
}