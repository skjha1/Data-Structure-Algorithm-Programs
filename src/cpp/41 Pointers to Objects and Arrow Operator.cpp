/*
Pointers to Objects

A variable that holds an address value is called  a pointer variable or simply pointer.
Pointer can point to objects as well as to simple data types and arrays.
sometimes we dont know, at the time that we write the program , how many objects we want to creat. when this is the case we can use new to creat  
objects while the program is running. new returns a pointer to an unnamed objects. lets see the example of student that wiil clear your idea about this topic


*/

#include<iostream>
using namespace std;

class Complex{
    int real, imaginary;
    public:
        void getData(){
            cout<<"The real part is "<< real<<endl;
            cout<<"The imaginary part is "<< imaginary<<endl;
        }

        void setData(int a, int b){
            real = a;
            imaginary = b;
        }

};
int main(){
    // Complex c1;
    // Complex *ptr = &c1;
    Complex *ptr = new Complex;
    // (*ptr).setData(1, 54); is exactly same as
    ptr->setData(1, 54);

    // (*ptr).getData(); is as good as 
    ptr->getData(); 


    // Array of Objects
    Complex *ptr1 = new Complex[4]; 
    ptr1->setData(1, 4); 
    ptr1->getData();
    return 0;
}
