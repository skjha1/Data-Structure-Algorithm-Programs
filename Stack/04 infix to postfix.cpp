#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
	int data;
	struct Node* next;
}*top=NULL;

void push(char x)
{
	struct Node *t;
	t = (struct Node*)malloc(sizeof(struct Node));
	if (t == NULL)
	{
		printf("Stack overflow");
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}

}
int pop()
{
	struct Node* p;
	int x = -1;
	if (top == NULL)
	{
		printf("Stack underflow");
	}
	else
	{
		p = top;
		top = top->next;
		x = p->data;
		free(p);
		
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

/****** Infix to Postfix Function*******/
char* InfixToPostfix(char* infix)								//function which takes pointer to a character array as parameter and returns pointer to a character array
{
	int i = 0, j = 0;												//i and j initialised with 0 which will help in accessing and scanning the character array
	char* postfix;												//pointer to a character array //it will hold the postfix notation created by the function
	int len = strlen(infix);									//len is assigned with the string length of the infix array that has been passed as an argument //it is done to allocate same size of memory for postfix array in the HEAP
	postfix = (char*)malloc((len + 1) * sizeof(char));			//memory is allocated for the postfix array inside the HEAP of size equal to (len+1) where len is string length of the infix array	// +1 has been added to len to store '\0' to make it a string

	while (infix[i] != '\0')										//Using while loop instead of for loop as i is not incrementing continuosly after every loop
	{
		if (isOperand(infix[i]))									//if the character in the infix array is an operand it must be copied directly into the postfix array
			postfix[j++] = infix[i++];							//postfix copies character of infix //i and j both are incremented
		else
		{
			if (precedence(infix[i]) > precedence(top->data))	//if precedence of the character of infix array is greater than the precedence of the character in the top of the stack		//CAUTION: as there is a chance of the top of stack getting NULL and to avoid accessing NULL->data (error), '#' is pushed in the stack before hand to avoid this problem
				push(infix[i++]);								//push the character of the infix array inside the stack //i is incremented
			else												//if precedence of the character of infix array is less or equal than the precedence of the character in the top of the stack
			{
				postfix[j++] = pop();							//pop the character from the stack and copy the popped character in the postfix array //j is incremented
			}
		}
	}

	//If any operators are left inside the stack, all must pe popped out and copied into the postfix array
	while (top->data != '#')									//Terminating condition for popping //'#' has been used to avoid the error of NULL->data (error)
		postfix[j++] = pop();								//characters are popped out of the stack one by one and copied in the postfix array

	postfix[j] = '\0';										//last index of postfix array is assigned with '\0' to make it a complete string

	return postfix;                                         //postfix array is returned as char *
}

int main()
{
	char infix [] = "a+b*c-d/e";   						     //infix expression
	push('#');												//'#' is pushed inside stack before hand to avoid the error of accessing NULL->data (error)

	char* postfix = InfixToPostfix(infix);					//calling the function for conversion

	printf("%s", postfix);
	return 0;
}