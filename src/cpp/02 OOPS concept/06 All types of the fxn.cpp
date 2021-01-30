// All type of function in one class 

#include <iostream>
using namespace std;

class Rectangle
{
private :
	int length;
	int breadth;
public:
	Rectangle();
	Rectangle(int l, int b);// -------> These are constructor 
	Rectangle(Rectangle& r);

	void setLength(int l);// ------> There are Mutators 
	void setBreadth(int b);

	int getLength() { return length; } // this became inline fxn 
	int getBreadth() { return breadth; }//  -----> These are accessor

	int area();
	int perimeter(); // ----------> These are Facilitators 

	bool isSquare(); // -----> This is Enquiry 
	

	~Rectangle(); //-----> This is destructor 

	// With the help of scope resol (::) we can access the member fxn of the class from outside of the class 

};
 //There are two methods of writting a fxn one is we can write directly inside the class other is we can write outside of the class using scope resolution 


Rectangle::Rectangle()
{
	length = 1;
	breadth = 1;
}


Rectangle::Rectangle(int l, int b)
{
	setLength(l);
	setBreadth(b);
}


Rectangle::Rectangle(Rectangle& r)
{
	length = r.length;
	breadth = r.breadth;
}


void Rectangle::setLength(int l)
{
	length = l;
}


void Rectangle::setBreadth(int b)
{
	breadth = b;
}


int Rectangle::area()
{
	return length * breadth;
}


int Rectangle :: perimeter()
{
	return 2 * (length + breadth);
}


bool Rectangle::isSquare()
{
	return length == breadth;
}


Rectangle::~Rectangle()
{
	cout << "Rectangle is destroyed ";
}


int main()
{
	/*Rectangle r(10, 5);
	cout << r.perimeter() << endl;*/

	Rectangle r(10, 10);
	cout << r.area() << endl;
	if (r.isSquare())
		cout << "This is a square "<<endl;
// destructor will automatically called at the last of the program 
	return 0;
}