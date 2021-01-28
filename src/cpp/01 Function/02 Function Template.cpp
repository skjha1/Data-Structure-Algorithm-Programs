//Function Template
//• Function template are used for defining generic functions
//• They work for multiple datatypes
//• Datatype is decided based on the type of value passed
//• Datatype is a template variable
//• Function can have multiple template variables

#include <iostream>
using namespace std;
template <class T>

T Maxi(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	int a = Maxi(4, 9);
	float b = Maxi(41.0f, 64.66f);
	cout << "The maximum of the integer number is " << a<<endl;
	cout << "The maximum of the floating point number is " << b<<endl;
	return 0;
}
