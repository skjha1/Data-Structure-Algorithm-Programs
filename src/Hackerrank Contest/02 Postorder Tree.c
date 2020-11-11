/*
Your task is to implement the following function :

void postorder(TreeNode*)
You will be working with the following structure :

struct TreeNode {
	int x;
    struct TreeNode* L;
    struct TreeNode* R;
}
You may only edit the BODY of the code, leaving the HEAD and the TAIL as it is.

Sample Input 0

7
4 2 1 3 6 7 5
Sample Output 0

1 3 2 5 7 6 4 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define scan(x) scanf(" %d", &x)
struct TreeNode {
	int x;
	struct TreeNode* L;
	struct TreeNode* R;
};
typedef struct TreeNode TreeNode;
TreeNode* newNode(int _x) {
	TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
	node->x = _x;
	node->L = node->R = NULL;
    return node;
}
TreeNode* insert(TreeNode* node, int val) {
	if (node == NULL) return newNode(val);
	if (val <= node->x) node->L = insert(node->L, val);
	else node->R = insert(node->R, val);
    return node;
}

void postorder(TreeNode* Root)
{
    if(Root)
    {
        postorder(Root->L);
        postorder(Root->R);
        printf("%d ",Root->x);
    }
}
int main() {
	int val, N; scan(N);
	TreeNode* Root = NULL;
	for (int i = 1; i <= N; i++) {
		scan(val);
		Root = insert(Root, val);
	}
	postorder(Root);
}