#include <stdio.h>
#include <stdlib.h>
struct Node
{
	char data;
	struct Node* next;
}*top=NULL;
// in c lang we dont have templete so we have to modify data member everywhere ;

void push(char x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));
	if (t == NULL)
		printf("Stack is full 0");
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}

}
int pop()
{
	struct Node* t;
	int x = -1;
	if (top == NULL)
		printf("Stack is empty ");
	else
	{
		t = top; 
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

void Display()
{
	struct Node* p;
	p = top;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int isBalanced(char* exp)
{
	int i; 
	for (i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == '(')
		{
			push(exp[i]);
		}
		else if(exp[i] == ')')
		{
			if (top == NULL) {
				return 0;
			}
			pop();

		}
	}
	if (top == NULL)
		return 1;
	else
		return 0; 
}



int main()
{
	char* exp = "((a+b)*(c-d))";
	printf("%d", isBalanced(exp));

	return 0; 
}
