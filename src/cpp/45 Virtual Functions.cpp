/*
A member function in the base class which is declared using virtual keyword is called virtual functions. They can be redefined in the derived class. 



*/


//To demonstrate the concept of virtual functions an example program is shown below

#include<iostream>
using namespace std;

class BaseClass{
    public:
        int var_base=1;
        virtual void display(){
            cout<<"1 Dispalying Base class variable var_base "<<var_base<<endl;
        }
};

class DerivedClass : public BaseClass{
    public:
            int var_derived=2;
            void display(){
                cout<<"2 Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"2 Dispalying Derived class variable var_derived "<<var_derived<<endl;
            }
};

int main(){
    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;

    base_class_pointer = &obj_derived;
    base_class_pointer->display();
    return 0;
}
/*
We created a pointer “base_class_pointer” of the data type “Baseclass”
Object “obj_base” of the data type “BaseClass” is created.
Object “obj_derived” of the data type “DerivedClass” is created
Pointer “base_class_pointer” of the base class is pointing to the object “obj_derived” of the derived class
The pointer “base_class_pointer” is pointed to the object “obj_derived” of the derived class.
The function “display” is called using the pointer “base_class_pointer” of the base class.
The main thing to note here is that if we don’t use the “virtual” keyword with the “display” function of the base class then beside of the point that we have pointed
our base call pointer to derived class object still the compiler would have called the “display” function of the base class because this is its default behavior
But we have used the “virtual” keyword with the “display” function of the base class to make is virtual function so when the display function is called by using the base
class pointer the display function of the derived class will run because the base class pointer is pointing to the derived class object.
*/
