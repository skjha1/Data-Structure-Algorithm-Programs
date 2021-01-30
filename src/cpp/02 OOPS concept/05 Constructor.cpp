// Philosopy behind constructor 
// suppose you want to buy a car with a color it is not like you will book the car and color it at your home we will take car which is alredy have our desiered color 
// There should be some value set to the class i.e there should not be a garbage value to class fxn
// in the same way we want to set Rectangle(l,b) in main rather than ; r.len/r.bre it is not a good habbit 
// so this is a philosopy behind the constructor 
// constructor is fxn which will have same name as the class name 
// constructir can not have the return type 
#include <iostream>
using namespace std;

class Rectangle
{
private :
	int length;
	int breadth;
public: // Compiler provider a default constructor. Moreover we are having our own costructor i.e(2,3,4)
	//1. Default | 2. Non parametersied -> this is not taking any para/argument it will set length and breadth =0 ; //rectangle ()/ rectangle 
				 //3.Parameter constructor -> Rectangle (int l, int b) ; setlen/setbre // rectangle (10,20);
				 //4. Copy constructor -> Readymade constructor Rectangle (Rectangle &r) ; len = r.len/ bre = r.bre; // Rectangle r2(r);


	// if we will not assign any constructor compiler will go for the  default constructor 



	//Rectangle() // this is known as non parametersied constructor // constructor should not have any return type 
	//{
	//	length = 1;
	//	breadth = 1;
	//}



	Rectangle(int l=1, int b=1) // this is the parametersied constructor // by mentionting value to the constructor you can remove the upper constructor 
	{
		setLength (l); // calling the member fxn;
		setBreadth(b);
	}


	Rectangle(Rectangle& r) // this is the copy constructor 
	{
		length = r.length;
		breadth = r.breadth;
	}






	void setLength(int l)
	{
		if (l >= 0)
			length = l;
		else
			length = 0;
		
	}
	void setBreadth(int b)
	{
		if (b >= 0)
			breadth = b;
		else
			breadth = 0;
	}
	int getLength(int l)
	{
		return length;
	}
	int getBreadth(int b)
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
	//Rectangle r;  // if we will not initialize any constructor then it will call by // Default consructor 
	//cout<<r.area()

	/*Rectangle r; // this is for the non parametersied constructor 
	cout << r.area() << endl;*/

	//Rectangle r(10, 20); // This is parameraised constructor 
	//cout << r.perimeter() << endl;

	Rectangle r(10,5); // copy constructor 
	Rectangle r1(r);
	cout << r1.area() << endl;
}