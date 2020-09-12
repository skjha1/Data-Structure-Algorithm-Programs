#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
}*top = NULL;

void push(int x)
{
	struct Node* t;
	t = (struct Node*)malloc(sizeof(struct Node));

	if (t == NULL)
		printf("Stack Overflow\n");
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop()
{
	int x = -1;
	struct Node* t;

	if (top == NULL)
		printf("Stack Underflow\n");
	else
	{
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

/********** Function to return precedence of the operators ********/
int precedence(char x)
{
	if (x == '+' || x == '-')					//if character (ie operator) is + or - return precedence as 1
		return 1;
	else if (x == '*' || x == '/')				//if character is * or / return precedence as 2
		return 2;
	else										//else return precedence as 0
		return 0;
}

/********** Function to check if a character in infix notation is an operand or not **********/
int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')		//if character is not an operand return false as 0
		return 0;
	else													//if character is an operand return true as 1
		return 1;
}

/************ Function to evaluate a postfix expression ********/
int Evaluation(char* postfix)
{
	int i;
	int x1, x2, r;										//x1 and x2 are variables to store the value of popped data from the stack //r will store the value after performing required arithmetic operations on x1 and x2


	for (i = 0; postfix[i] != '\0'; i++)
	{
		if (isOperand(postfix[i]))						//if it is an operand it should be pushed inside the stack
			push(postfix[i] - '0');						//since stack is of integer type it cannot hold a character //operands in the postfix expression are just characters //hence the actual value relevant to the character must be pushed inside the stack //for this '0' (ascii value 48) must be subtracted from the numeric character in order to get the actual value representing that character in the expression
		else
		{
			x2 = pop();						//x2 should be popped out first in order to maintain the expression	//first one to get out becomes the second operand for the operation
			x1 = pop();						//x1 should be popped after x2										//last one to get out becomes the first operand for the operation

			switch (postfix[i])				//switch procedure to perform the required arithmetic operations on both the popped out operands
			{
			case '+':
				r = x1 + x2;
				break;
			case '-':
				r = x1 - x2;
				break;
			case '*':
				r = x1 * x2;
				break;
			case '/':
				r = x1 / x2;
				break;
			}
			push(r);						//r is pushed as an operand inside the stack to proceed futher	
		}
	}
	return top->data;						//after performing all operations final value remains inside the stack and it is returned
}

int main()
{
	char postfix []= "35*62/+4-";

	printf("Result: %d", Evaluation(postfix));
	return 0;
}