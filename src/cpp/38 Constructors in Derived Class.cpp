/*
We can explicitly mention to call the Base class's parameterized constructor when Derived class's parameterized constructor is called.
Whenever we create an object of a class, the default constructor of that class is invoked automatically to initialize the members of the class.
If we inherit a class from another class and create an object of the derived class, it is clear that the default constructor of the derived class will be invoked but 
before that the default constructor of all of the base classes will be invoke, i.e the order of invokation is that the base class’s default constructor will be invoked
first and then the derived class’s default constructor will be invoked.

Why the base class’s constructor is called on creating an object of derived class?

To understand this you will have to recall your knowledge on inheritance. What happens when a class is inherited from other?
The data members and member functions of base class comes automatically in derived class based on the access specifier but the definition of these members exists in 
base class only. So when we create an object of derived class, all of the members of derived class must be initialized but the inherited members in d
erived class can only be initialized by the base class’s constructor as the definition of these members exists in base class only. This is why the constructor of 
base class is called first to initialize all the inherited members.

class Base
*/

#include<iostream>
using namespace std;
/*
Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/

class Base1{
    int data1;
    public:
        Base1(int i){
            data1 = i;
            cout<<"Base1 class constructor called"<<endl;
        }
        void printDataBase1(void){
            cout<<"The value of data1 is "<<data1<<endl;
        }
};

class Base2{
    int data2;

    public:
        Base2(int i){
            data2 = i;
            cout << "Base2 class constructor called" << endl;
        }
        void printDataBase2(void){
            cout << "The value of data2 is " << data2 << endl;
        }
};

class Derived: public Base2, public Base1{
    int derived1, derived2;
    public:
        Derived(int a, int b, int c, int d) : Base2(b), Base1(a)
        {
            derived1 = c;
            derived2 = d;
            cout<< "Derived class constructor called"<<endl;
        }
        void printDataDerived(void)
        {
            cout << "The value of derived1 is " << derived1 << endl;
            cout << "The value of derived2 is " << derived2 << endl;
        }
};
int main(){
    Derived harry(1, 2, 3, 4);
    harry.printDataBase1();
    harry.printDataBase2();
    harry.printDataDerived();
    return 0;
}
