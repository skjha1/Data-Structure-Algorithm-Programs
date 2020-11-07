/* Why Object-Oriented Programming?
Before we discuss object-oriented programming, we need to learn why we need object-oriented programming?

C++ language was designed with the main intention of adding object-oriented programming to C language
As the size of the program increases readability, maintainability, and bug-free nature of the program decrease.
This was the major problem with languages like C which relied upon functions or procedure (hence the name procedural programming language)
As a result, the possibility of not addressing the problem adequately was high
Also, data was almost neglected, data security was easily compromised
Using classes solves this problem by modeling program as a real-world scenario


Difference between Procedure Oriented Programming and Object-Oriented Programming
Procedure Oriented Programming
Consists of writing a set of instruction for the computer to follow
The main focus is on functions and not on the flow of data
Functions can either use local or global data
Data moves openly from function to function


Object-Oriented Programming
Works on the concept of classes and object
A class is a template to create objects
Treats data as a critical element
Decomposes the problem in objects and builds data and functions around the objects


Basic Concepts in Object-Oriented Programming
Classes - Basic template for creating objects
Objects – Basic run-time entities
Data Abstraction & Encapsulation – Wrapping data and functions into a single unit
Inheritance – Properties of one class can be inherited into others
Polymorphism – Ability to take more than one forms
Dynamic Binding – Code which will execute is not known until the program runs
Message Passing – message (Information) call format


Benefits of Object-Oriented Programming
Better code reusability using objects and inheritance
Principle of data hiding helps build secure systems
Multiple Objects can co-exist without any interference
Software complexity can be easily managed

Why use classes instead of structures
Classes and structures are somewhat the same but still, they have some differences. 
For example, we cannot hide data in structures which means that everything is public 
and can be accessed easily which is a major drawback of the structure because structures 
cannot be used where data security is a major concern. Another drawback of structures is 
that we cannot add functions in it.

Classes in C++
Classes are user-defined data-types and are a template for creating objects. Classes consist of vari
ables and functions which are also called class members.


Public Access Modifier in C++
All the variables and functions declared under public access modifier will be available 
for everyone. They can be accessed both inside and outside the class. Dot (.) operator is used in the program to access public data members directly.

Private Access Modifier in C++
All the variables and functions declared under a private access modifier can only be used inside the class.
 They are not permissible to be used by any object or function outside the class.

*/
#include<iostream>
using namespace std;

class Employee
{
    private:
        int a, b, c;
    public:
        int d, e;
        void setData(int a1, int b1, int c1); // Declaration
        void getData(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};

void Employee :: setData(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    Employee harry;
    // harry.a = 134; -->This will throw error as a is private
    harry.d = 34;
    harry.e = 89;
    harry.setData(1,2,4);
    harry.getData();
    return 0;
}
