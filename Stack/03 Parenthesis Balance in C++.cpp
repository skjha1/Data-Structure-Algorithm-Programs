#include <iostream>
#include<cstring> //Including header file for using string function(strlen..) 
using namespace std;

class Node { // structure for stack using linkedlist
public:
    char data; // data part of the node 
    Node* next; // pointer to the next node 
};

class Stack {
private:
    Node* top;
public:
    Stack(); // non parametrized constructor 
    ~Stack(); // destructor 
    void push(char x); // declaration of push operation 
    char pop(); // declaration of  the pop operation
    char peek(int index); // declaration for getting the element at an given index 
    int isEmpty(); // declaration for checking the stack empty codition 
    int isFull(); // declaration for checking the stack full condition
    char stackTop(); // declaration for getting the topmost value of the stack
};

Stack::Stack() {
    top = nullptr; // initilize top pointer as null
}

Stack::~Stack() {
    Node* p = top; // create a new pointer p and make it point on top
    while (top) {
        top = top->next; // everytime move top to next 
        delete p; // free p
        p = top; // move p on the top
    }
}

void Stack::push(char x) {// function for pushing element in the stack
    Node* t = new Node;// creating a new node 
    if (t == nullptr) { // if node is not created // i.e if heap memory is full 
        cout << "Stack Overflow!" << endl; // print that stack is overflow
    }
    else {
        t->data = x; // fill the node data part with data 
        t->next = top; // point the next of the node to the top of the stack
        top = t; // and move top to the newly created node 
    }
}

char Stack::pop() { // function for deleting the element from the stack
    Node* p; // ccreate a new node 
    char x = -1; // assign x with -1;
    if (top == nullptr) { // if top is null// i.e stack is empty 
        cout << "Stack Underflow!" << endl; // print that stack is underflow
    }
    else {
        p = top; // move p on to the top 
        x = p->data; // take out the data from top of the stack
        top = top->next; // everytime move top its next 
        delete p; // at last free the space of p
    }
    return x; // return the value which has deleted 
}

int Stack::isFull() { // function for checking the stack is full or not 
    Node* t = new Node; // creating a new node 
    int r = t ? 1 : 0; // if new node is created then stack is not full else stack is full 
    delete t; // free space consumed by the new node
    return r; // return the condition
}

int Stack::isEmpty() { // checking either stack is empty or not 
    return top ? 0 : 1; // if top is pointing to null the  stack is empty else stack is full
}

char Stack::stackTop() { // returning the topmost element of the stack
    if (top) { // if top is there 
        return top->data; // then return the value in the top pointer 
    }
    return -1;
}

char Stack::peek(int index) { // function for taking the element at an particular index 
    if (isEmpty()) { // if stack is empty then return the value -1
        return -1;
    }
    else {
        Node* p = top; // create a new pointer p and make move that p onto the top 

        for (int i = 0; p != nullptr && i < index - 1; i++) { // iterating through the stack 
            p = p->next; // everytime move p to next 
        }

        if (p != nullptr) { // if p is not null then
            return p->data; // return the value of that node 
        }
        else {
            return -1; // else return -1 for stack empty 
        }
    }
}


int isBalanced(char* exp) {
    Stack stk; // creating a local  varible of stack type  // charater type stack 

    for (int i = 0; i < strlen(exp); i++) { // iterating throuhout the stack
        if (exp[i] == '(') { // if there is starting parenthisis is there then 
            stk.push(exp[i]); // push that to the stack 
        }
        else if (exp[i] == ')') { // whereas if closing parenthesis is there 
            if (stk.isEmpty()) { // check either stack is empty or not if stack is empty then return false as expression is mot balenced 
                return false;
            }
            else {
                stk.pop(); // pop out the closing parenthesis 
            }
        }
    }
    return stk.isEmpty() ? true : false; // if at last the stack is empty then return true for expression is balanced whereas false for expression is not balanced 
}


int main() {

    char E[] = "((a+b)*(c-d))"; // expression to be evaluated 
    cout << isBalanced(E) << endl; // calling the function 

    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;

    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;

    return 0;

}
