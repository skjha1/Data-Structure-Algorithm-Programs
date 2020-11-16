#include<iostream>
using namespace std;

// code resuablity // avoid fxn overloading // once written and use it many times 
template <class T > 
T mymax(T a, T b)
{
	return (a > b) ? a : b; // if a is greater then b print a else b // it is ternary operator it encapusulates if-else-return in one line 
}
int main() {
	cout << mymax<int>(9, 10) << endl;
	cout << mymax<float>(20.3, 6.7) << endl;
	cout << mymax<char>('E', 'A')<<endl;
	return 0;
}