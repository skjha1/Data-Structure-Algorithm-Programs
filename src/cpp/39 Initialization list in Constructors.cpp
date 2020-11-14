#include <iostream>
using namespace std;
/*
Initializer List is used in initializing the data members of a class. The list of members to be initialized is indicated with constructor as a comma-separated list 
followed by a colon. Following is an example that uses the initializer list to initialize x and y of Point class.


Syntax for initialization list in constructor:
constructor (argument-list) : initilization-section
{
    assignment + other code;
}

class Test{
    int a;
    int b;
    public:
        Test(int i, int j) : a(i), b(j){constructor-body}
};

*/
class Test
{
    int a;
    int b;

public:
    // Test(int i, int j) : a(i), b(j)
    // Test(int i, int j) : a(i), b(i+j)
    // Test(int i, int j) : a(i), b(2 * j)
    // Test(int i, int j) : a(i), b(a + j)
    // Test(int i, int j) : b(j), a(i+b) -->RED Flag this will create problems because a will be initialized first
    Test(int i, int j)
    {
        a = i;
        b = j;
        cout << "Constructor executed"<<endl;
        cout << "Value of a is "<<a<<endl;
        cout << "Value of b is "<<b<<endl;
    }
};

int main()
{
    Test t(4, 6);

    return 0;
}
