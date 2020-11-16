/* Like function templates, class templates are useful when a class defines something that is independent of data type. 
Can be useful for classes like LinkedList, binary tree, Stack, Queue, Array, etc.

We can pass more than one data types as arguments to templates.
*/

#include<iostream>
using namespace std;
template <class T>
class Array {
private :
	T* ptr;
	int size;
public:
	Array(T arr[], int  s);
	void print();
};

template <class T>
Array<T> :: Array(T arr[], int s)
{
	int i;
	ptr = new T[s];
	size = s;
	for (i = 0; i < size; i++)
		ptr[i] = arr[i];
}
template <class T>
void Array<T> ::print()
{
	int i;
	for (i = 0; i < size; i++)
		cout <<" " << *(ptr + i);
	cout <<endl;
}
int main()
{
	int no;
	int arr[10];
	cout << "enter the size of array "<<endl;
	cin >> no;
	cout << "Enter all the elements of array " << endl;
	for (int i = 0; i < no; i++)
		cin >> arr[i];
	Array<int> a(arr, no);
	a.print();
	return 0;
}