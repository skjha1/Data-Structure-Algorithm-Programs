// inline fxn will call itself with the fxn else it is called outside and take memory outside we will use just inline keyword 
// let us understand this function 

#include <iostream>
using namespace std;

class Rectangle
{
private :
	int length;
	int breadth;
public:
	Rectangle(int length, int breadth) // here we need use to this fxn inored to show that private data is assigned to this parameter
	{
		this->length = length; // it removes the ambiguity between the parameters of the class 
		this->breadth = breadth;
	}

	int area()
	{
		return length * breadth;
	}
};

int main()
{
	Rectangle r(1, 5);
	cout << r.area() << endl;
	return 0;
}