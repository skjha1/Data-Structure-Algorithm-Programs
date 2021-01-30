#include <iostream>
using namespace std;

class Rectangle
{
public:
	int length; // Data members // only data member will occupy memory fxn will not occupy any memory
	int breadth;

	int area() {// member function 
		return length * breadth; 
	}
	int perimeter() {
		return 2 * (length + breadth);
	}
};

void main()
{
	Rectangle r1, r2; // total it is going to take 4 bytes (2 for length and 2 for breadth)// here we created two objects for rec class 
	r1.length = 10; // dot operator is used to access data member of the class 
	r1.breadth = 5;
	cout << r1.area() <<endl; // this will not occupy memory
	r2.length = 15;
	r2.breadth = 54;
	cout << r2.area() << endl; // dot operator is used to access member fxn from the class 

}