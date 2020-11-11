/*
Your task is to write a program to print the zigzag level-order traversal of a binary tree.
Here are a few examples :

  1
 / \
2   3
Traversal : 1 3 2
    1
   / \
  2   3
 / \   \
4   5   6
Traversal : 1 3 2 4 5 6
       1
      / \
     2   3
    / \   \
   4   5   6
  /   /   / \
 7    8  9   10
 Traversal : 1 3 2 4 5 6 10 9 8 7
Input
First line contains the number of nodes N.
Next N-1 lines contains information about one edge each.
Each line consists of three values : U V C which denotes that V is a child of U
If C is 'L' then V is a left child and if C is 'R' then V is a right child

Output
Print the zigzag level order traversal as explained

Sample Input 0

3
1 2 L
1 3 R
Sample Output 0

1 3 2
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int l;
    int r;
    //int data;
}a[10000];
int stack1[1000],stack2[10000];
int top1=-1,top2=-1;
void push1(int v)
{
    stack1[++top1]=v;
}
void push2(int v)
{
    stack2[++top2]=v;
}
int pop1()
{
    return stack1[top1--];
}
int pop2()
{
    return stack2[top2--];
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a[i].l=0;
        a[i].r=0;
    }
    for(int i=0;i<n-1;i++)
    {
        int d,c;
        char f;
        scanf("%d %d %c",&c,&d,&f);
        if(f=='L')
            a[c].l=d;
        else
            a[c].r=d;
    }
    push1(1);
   // printf("%d\t%d\n",top1,top2);
    while(top1>=0 || top2>=0)
    {
        while(top1>=0)
        {
            k=pop1();
            printf("%d ",k);
            if(a[k].l!=0)
            push2(a[k].l);
            if(a[k].r!=0)
                push2(a[k].r);
        }
       /* for(int i=top2;i!=-1;i--)
            printf("\nstack %d \n",stack2[i]);
        */
        while(top2>=0)
        {
            k=pop2();
            printf("%d ",k);
            if(a[k].r!=0)
                push1(a[k].r);
            if(a[k].l!=0)
                push1(a[k].l);
        }
    }

    return 0;
}