#include<iostream>
// Here namespace is having obj like cin and cout ; 
using namespace std;
class Array  // Creating class 
// Class in c++ will have Datamember and member function
{
	private:
	int *A;  // Creating in heap so that i can  dynamically create an array 
	int size;
	int length;
	
	public: // Member function must be inside public 
	// Write an constructor
	Array () // This is non parameter constructor
	{
		size=10;
		A = new int[10]; // dynamically created array in heap
		length=0;
		
	}
	
	// parametetrzied Constructor 
	
	Array (int sz)
	{
		size=sz;
		length=0;
		A=new int [size];
	}
	
	
//	We must have destructors to release resourses
	~Array()     // Creating Destructor 
	{
		delete []A;
	}
	
	// Writting Function 
	void Display (); // There sud not be parameter cz this is part of Array function 
	void Insert (int index, int x);
	int Delete (int index);
	
};

void Array :: Display ()
{
	for (int i=0; i<length;i++)
	cout<<A[i]<<" ";
	cout<<endl;
}

// Now to access element from array class we will use Scope Resolution (::) followed by Class name 

void Array :: Insert (int index , int x)
{
	if (index >=0 && index <=length )
	{
		for (int i=length-1;i>index;i--)
		A[i+1]=A[i];
		A[index]=x;
		length++;
	}
 }

int Array :: Delete (int index)
{
	int x=0;
	if (index>=0 && index <length)
	{
		x=A[index];
		for ( int i=index ; i<length-1; i++)
		A[i]==A[i+1];
		length --;
	}
	return x;
}
int main ()
{
	Array arr(10);
	arr.Insert(0,5);
	arr.Insert(1,25);
	arr.Insert(2,56);
	arr.Insert(3,99);
	cout<<arr.Delete(0)<<endl;
	arr.Display();
	return 0;
}



