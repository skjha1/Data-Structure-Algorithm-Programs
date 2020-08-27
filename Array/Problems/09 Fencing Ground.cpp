#include<iostream>
using namespace std;
int main ()
{
	int length,width;
	
	cin>>length>>width;
	int prm= 2*(length+width);
	int area = length*width ;
	cout << "Length= "<<prm<<" m";
	cout<<"Quantity= "<<area<<" sqm";
	return 0;
	
}
