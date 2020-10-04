#include<iostream>
using namespace std;
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	
}
int main() 
{
	int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << "swap is " << a<<" "<<b;
	return 0;

}