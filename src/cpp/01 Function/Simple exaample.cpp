
//Functions
//• Function is a module which performs a specific task
//• Functions are called by name
//• Rules for giving function name is same as variable name
//• Function can take 0 or more parameters
//• Function can return single value
//• Void function don’t return any value
//• Default return type is int

#include <iostream>
using namespace std;

void Dispaly()
{
	cout << "Hello world " << endl; // dont use cin and cout inside fxn it is not a good habbit 
}

float add(float x, float y)
{
	float z;
	z = x + y;
	return z;
}

int maxi(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	else if (b > c)
		return b;
	else
		return c;
}

int main()
{
	//Dispaly();


	//float x = 2.3, y = 6.3;
	//cout<<add(x, y)<<endl;

	int a, b, c, d;
	cout << "Enter three no.s ";
	cin >> a >> b >> c;
	d = maxi(a, b, c);
	cout << "Maximum is " << d << endl;
	
	return 0;
}
