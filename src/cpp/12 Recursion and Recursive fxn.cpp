#include<iostream>
using namespace std;

int fib(int n){
    if(n<2){
        return 1;
    }
    return fib(n-2) + fib(n-1);
}

// fib(5)
// fib(4) + fib(3)
// fib(2) + fib(3) + fib(2) + fib(3)

int factorial(int n){
    if (n<=1){
        return 1;
    }
    return n * factorial(n-1);
}

// Step by step calculation of factorial(4)
// factorial(4) = 4 * factorial(3); 
// factorial(4) = 4 * 3 * factorial(2);
// factorial(4) = 4 * 3 * 2 * factorial(1);
// factorial(4) = 4 * 3 * 2 * 1;
// factorial(4) = 24;

int main(){
    // Factorial of a number:
    // 6! = 6*5*4*3*2*1 = 720
    // 0! = 1 by definition
    // 1! = 1 by definition
    // n! = n * (n-1)!
    int a;
    cout<<"Enter a number"<<endl;
    cin>>a;
    // cout<<"The factorial of "<<a<< " is "<<factorial(a)<<endl;
    cout<<"The term in fibonacci sequence at position "<<a<< " is "<<fib(a)<<endl;
    return 0;
}

/*
When a function calls itself it is called recursion and the function which is 
calling itself is called a recursive function. The recursive function consists of
 a base case and recursive condition. It is very important to add a base case in recursive function
 otherwise recursive function will never stop executing.

 */