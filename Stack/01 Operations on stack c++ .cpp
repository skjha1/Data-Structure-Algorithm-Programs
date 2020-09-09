#include <stdio.h>
#include <stdlib.h>
struct Stack { // struct for stack 
	int size;  // size of  stack 
	int top; // top pointer to point on top of stack 
	int* S; //  Create a array dynamically  for storing elements 
};

void create(struct Stack* st)
{
	printf("enter size of stack ");
	scanf_s("%d", &st->size);
	st->top = -1; // set top of stack as -1 initially 
	st->S = (int*)malloc(st->size * sizeof(int)); // array is created dynamically 

}
void Display(struct Stack st) // call by value bcz it is not going to modify stack 
{
	int i;
	for (i =st.top; i >= 0; i--)
		printf("%d ", st.S[i]);
	printf("\n");

}

void Push(struct Stack* st,int x)
{
	if (st->top == st->size - 1) // check wheather stack is full 
		printf("Stack overflow \n ");
	else
	{
		st->top++;
		st->S[st->top] = x;
	}
}

int pop(struct Stack* st)
{
	int x = -1; //  if element is not found 
	if (st->top == -1) // stack is empty 
		printf("Stack Underflow ");
	else
	{
		x = st->S[st->top--];
		 
	}
	return x;


}
int peek(struct Stack st, int index)
{
	int x = -1;
	if (st.top - index + 1 < 0)
		printf("Invalid Index \n");
	x = st.S[st.top - index + 1];

	return x;
}
int isEmpty(struct Stack st)
{
	if (st.top == -1)
		return 1;
	return 0;
}
int isFull(struct Stack st)
{
	return st.top == st.size - 1;
}
int stackTop(struct Stack st)
{
	if (!isEmpty(st))
		return st.S[st.top];
	return -1;
}
int main()
{
	struct Stack st; 
	create(&st);
	Push(&st, 10);
	Push(&st, 20);
	Push(&st, 30);
	Push(&st, 40);
	
	printf("topmost value is %d\n",peek(st,2)); // returns thye topmost value 
	printf("del element is %d\n", pop(&st)); // it will return the deleted element 
	printf("stack is %d\n", isEmpty(st)); // 1 if empty 0 if full
	printf("stack is %d\n", isFull(st)); // 1 if full 0 if not full
	printf("stack is %d\n", stackTop(st)); // returns the topmost elements in stack 

	Display(st);
	return 0; 
}