// DATA HIDING 

// In previous examples seen that data member of the class were public that was accessed by anyone outside the function 
// This does not shows a good habbit a programming here comes the concept of the abstraction // if we will keep breadth as -5 and we will get -ve area that is not possible
// let us see how we can do that we will make data member as private and member fxn as public 
// by default class data member are private 
// then how we are going to access the data membe outside the function // if we will not set value we will get a garbage value 
// 

#include <iostream>
using namespace std; 

class Rectangle
{
private: // we made it private in order hide abstraction 
	int length;
	int breadth;
public:
	void setLength(int l)
	{
		if (l >= 0)
			length = l;
		else
			length = 0;
		
	}
	void setBreadth(int b) // mutator 
	{
		if (b >= 0)
			breadth = b;
		else
			breadth = 0;
		
	}
	int getLength() // accessore // together mutator and accessor known as property fxn /.
	{
		return length;
	}
	int getBreadth()
	{
		return breadth;
	}
	int area()
	{
		return length * breadth;
	}
	int perimeter()
	{
		return 2 * (length + breadth);
	}
};

void main()
{
	Rectangle r;
	r.setLength(10);
	r.setBreadth(5);

	cout <<"The area of the rectangle is "<< r.area() << endl;
	cout << "The perimeter of the rectangle " << r.perimeter() << endl;	
	
}