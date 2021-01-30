// The difference btw struct and class 
// this struct is more like class 
// in struct everything by defalut public whereas in class everything is by default private  this is only the difference 
#include <iostream>
using namespace std;

struct Demo // we can keep class on the place of struct by making the data member public 
{
	int x;
	int y;

	void Display()
	{
		cout << x << " " << y << endl;
	}
};

int main()
{
	Demo d;
	d.x = 20;
	d.y = 10;
	d.Display();
	return 0;
}