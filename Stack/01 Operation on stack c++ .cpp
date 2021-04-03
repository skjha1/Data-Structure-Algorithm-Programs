#include <iostream>
using namespace std;

class Stack {
private: // Structure for stack!
    int size; // size of the stack
    int top; // this will decide the situation of the stack 
    int* S; // stack Pointer to create dynamically 
public:
    Stack(int size); // Creating a parametrized constructor by class name by passing the size of the stack 
    ~Stack(); // Destructor to remove from memory 
    void push(int x); // delaclartion of push function i.e for inserting an element at the top of stack
    int pop(); // declaration for the pop i.e deleting the topmost element
    int peek(int index); // declaration of peek, knowing the element at particular index 
    int isFull(); // declaration of isfull, this will check either the stack is full or not
    int isEmpty(); // declaration of isempty this will check either stack is empty or not
    void display(); // declaration of Display for displaying the stack 
    int stackTop(); // declaration of the stacktop for checking the topmost element present in the stack 
};

Stack::Stack(int size) { // this will create the size of the stack 
    this->size = size; // this is used bcz we have same name parameter so assigning this function size to the private class size 
    top = -1; // intially set top of the stack as -1;
    S = new int[size]; // dynamically creating the size of the stack in heap memory 
}

Stack::~Stack() {
    delete[] S; // after using free the memory from heap 
}

void Stack::push(int x) { // this function is for inserting element at the top of stack 
    if (isFull()) { // checking the condition if stack is full then we can't insert further any elements 
        cout << "Stack Overflow!" << endl; // so print a message that stack is full 
    }
    else { // if stack is not full the 
        top++; // increment top 
        S[top] = x; // and push the element to stack 
    }
}

int Stack::pop() {// deleting the element from the stack 
    int x = 1; // initially setting x as one 
    if (isEmpty()) { // checking the stack either it is empty if empty there is no meaning for deletion of the element 
        cout << "Stack Underflow!" << endl; 
    }
    else {
        x = S[top]; // take out the element and then decrement the size of the stack
        top--; // decreament the size of the stack 
    }
    return x;
}

int Stack::peek(int index) { // taking out the element from a particular index 
    int x = -1;
    if (top - index + 1 < 0 || top - index + 1 == size) { // 1st of all check either the stack index is valid or not; it should be greater then 0 and less the size
        cout << "Invalid position!" << endl; // if is does not shows a proper index then print invalid index 
    }
    else {
        x = S[top - index + 1]; // and if the index is valid then take out the element 
    }
    return x; // and return it 
}

int Stack::isFull() { // checking either a stack is full
    if (top == size - 1) { // if the top 
        return 1;
    }
    return 0;
}

int Stack::isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

void Stack::display() { // since stack is lifo consider it as verticle cane of ball and taking elements at time 
    for (int i = top; i >= 0; i--) {
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}

int Stack::stackTop() {
    if (isEmpty()) {
        return -1;
    }
    return S[top];
}


int main() {

    int A[] = { 1, 3, 5, 7, 9 };
// inside main function we will create a object of stack 
    Stack stk(sizeof(A) / sizeof(A[0]));

    // Populate stack with array elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        stk.push(A[i]);
    }
    stk.push(11);

    cout << "Stack full: " << stk.isFull() << endl;

    // Display stack;
    cout << "Stack: " << flush;
    stk.display();

    // Peek
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;

    // Top element
    cout << "Top element: " << stk.stackTop() << endl;

    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();

    cout << "Stack empty: " << stk.isEmpty() << endl;

    return 0;
}
