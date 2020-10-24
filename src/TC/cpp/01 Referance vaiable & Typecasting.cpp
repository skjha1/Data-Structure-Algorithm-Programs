#include <iostream>
using namespace std;
// now suppose we want to create a global variable that will be outside
int c = 45;
int main()
{
	// ******************** Build in Datatypes *********************************
	int a, b, c; // this is the local variable
	
	cout << "enter the 1st value "<<endl;
	cin >> a;
	cout << "enter the second value "<<endl;
	cin >> b;
	c = a + b;
	cout << "the sum of the no is " << c<<endl; // accessing local variable 
	// if we want to use the global varible inside the main function then we have to use scope resolution 
	cout << "the value of c is " << ::c<<endl; 


	// ******************** Float double and long double referls  *********************************
	float d = 55.8f; // we wrote f to make it as float value 
	long double e = 55.8l; // by default decimal is consider as float// we kept l bcz it is long double 
	cout << "the value of d is " << d << endl << "The value of e is " << e<<endl;

	cout << "the size of 55.8 is " << sizeof(55.8) << endl; // bydefault double 8
	cout << "the size of 34.4f is " << sizeof(55.8f)<<endl;// 4
	cout << "the size of 55.8F is " << sizeof(55.8F) << endl;//4
	cout << "the size of 55.8l is " << sizeof(55.8l) << endl; //8
	cout << "the size of 55.8L is " << sizeof(55.8L) << endl;//8 // it depends on the bit of os 


	// ******************** Reference variable  *********************************
	// shivendra(school) ----->shivam(home) ------> shiv (friend)-------->programmer (himself )

	float x = 4555;
	float& y = x;
	cout << x << endl;// 4555
	cout << y << endl;//4555

	// ******************** Typecasting(changing one variable to another ) *********************************

	int n = 45;
	float m = 45.99;
	cout << "the value of n is " << (float)n<<endl;
	cout << "the value of n is " << float(a) << endl;

	cout << "the value of m is " << (int)m<<endl;
	cout << "the value of b is " << int(m) << endl;



	cout << "the expression is " << m + n << endl;
	cout << "the expression is " << n + int(m)<< endl;
	cout << "the expression is " << n + (int)m << endl;

	return 0; 
}