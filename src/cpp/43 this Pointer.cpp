/*
Every object in C++ has access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter to all member functions.
Therefore, inside a member function, this may be used to refer to the invoking object.

Friend functions do not have a this pointer, because friends are not members of a class. Only member functions have a this pointer.
*/

#include<iostream>
using namespace std;
class A{
    int a;
    public:
        // A & setData(int a){
        void setData(int a){
            this->a = a;
            // return *this;
        }

        void getData(){
            cout<<"The value of a is "<<a<<endl;
        }
};

int main(){
    // this is a keyword which is a pointer which points to the object which invokes the member function
    A a;
    a.setData(4);
    a.getData();
    return 0;
}
