//Function Overloading
//• If More than one functions can have same name, but different parameter list, then they
//are overloaded functions
//• Return the is not considered in overloading
//• Function overloading is used for achieving compile time polymorphism

#include<iostream>
using namespace std;

int Sum(int a, int b)
{
	return a + b;
}

float Sum(float a, float b)
{
	return a + b;
}

int Sum(int a, int b, int c)
{
	return a + b + c;
}

int main()
{
	cout <<"Sum using two parameter "<< Sum(1, 8)<<endl;
	cout <<"Sum using two floating point parameter "<< Sum(1.9f, 8.5f)<<endl;
	cout <<"Sum using three parameter "<< Sum(1, 8,85)<<endl;
	return 0;
}
