#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	char data;
	struct Node* next;
}*top = NULL;

void push(char x)
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

char pop()
{
	char x = -1;
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

/***** Function to return precedence for operators outside the stack *******/
int OutStackPre(char x)
{
	if (x == '+' || x == '-')			//if operators outside are + and -
		return 1;						//precedence should increase from 1 to 2 from outStack to InStack since it has Left to Right Associativity
	else if (x == '*' || x == '/')		//if operators outside are * and /
		return 3;						//precedence should increase from 3 to 4 from OutStack to Instack since it has Left to Right Associativity
	else if (x == '^')					//if operator outside is ^
		return 6;						//precedence should decrease from 6 to 5 from OutStack to Instack since it has Right to Left Associativity
	else if (x == '(')					//if it is an opening bracket (
		return 7;						//it has highest precedence
	else if (x == ')')					//if it is a closing bracket
		return 0;						//Closing bracket need not to be pushed inside the stack hence closing bracket ) has lowest precedence of 0
	else
		return -1;						//for invalid character
}

/***** Function to return precedence for operators inside the stack ******/
int InStackPre(char x)
{
	if (x == '+' || x == '-')
		return 2;						//precedence inside stack increases from 1 to 2 for + and - since it has Left to Right Associativity
	else if (x == '*' || x == '/')
		return 4;               		//precedence inside stack increases from 3 to 4 for * and / since it has Left to Right Associativity
	else if (x == '^')
		return 5;						//precedence inside stack decreases from 6 to 5 for ^ since it has Right to Left Associativity
	else if (x == '(')
		return 0;						//precedence inside stack decreases from 7 to 0 //special case to handle '(' and ')' situation inside the stack //as ')' has always outstack precedence of 0 and '(' has always instack precedence of 0 so if both instack and outstack precedence get equals in this case '(' is popped out from the stack
	else
		return -1;						//for invalid character
}

/***** Function to check if a character in infix notation is an operand or not ******/
int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
		return 0;
	else
		return 1;
}

/******* Infix to Postfix Function *******/
char* InfixToPostfix(char* infix)
{
	int i = 0, j = 0;
	char* postfix;
	int len = strlen(infix);
	postfix = (char*)malloc((len + 1) * sizeof(char));

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (OutStackPre(infix[i]) > InStackPre(top->data))			//if the precedence of the character outside the stack is greater than the precedence of the character inside the stack
				push(infix[i++]);										//push the character from outside to inside of the stack  //point to be noted: logically after pushing the character inside the stack its precedence increases or decreses according to its associativity
			else
			{
				if (OutStackPre(infix[i]) == InStackPre(top->data))		//it is a special condition for brackets '()' //if a ')' bracket appears outside the stack in the expression its precedence is 0 and if '(' is present inside the stack its precedence is also 0 hence the '(' is popped out of the stack to balance the ')'
				{
					pop();
					i++;
				}
				else
					postfix[j++] = pop();
			}
		}
	}

	//If operators are left inside the stack, all must be popped out
	while (top->data != '#')								//termination condition for the stack to avoid NULL->data (error)
		postfix[j++] = pop();

	postfix[j] = '\0';

	return postfix;
}

int main()
{
	char infix[] = "((a+b)*c)-(d^e^f)";   						     //infix expression
	push('#');												//'#' is pushed inside stack before hand to avoid the error of accessing NULL->data (error)

	char* postfix = InfixToPostfix(infix);					//calling the function for conversion

	printf("%s", postfix);
	return 0;
}