#include <iostream>
using namespace std; 

class Rectangle
{
public:
	int l;
	int b;

	int area()
	{
		return l * b;
	}
	int perimeter()
	{
		return 2 * (l + b);
	}
};

void main()
{
	Rectangle r1;
	r1.l = 5;
	r1.b = 8;
	cout << "The Area of the rectangle is " << r1.area() << endl;
	cout << "The Perimeter of the rectangle is " << r1.perimeter() << endl;
}