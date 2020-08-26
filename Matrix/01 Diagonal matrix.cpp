#include <iostream>
using namespace std;
class Diagonal // Difining a diagonal class 
{
	private: // passing datamembers with private
		int n; // Dimension
		int *A; // array as pointer
	public: // inside public the very 1st thing is constructor 
	Diagonal() // non parametrized constructor 
	{
		n=2;
		A= new int[2];
	}
	Diagonal (int n) // parametarized constructor 
	{
		this->n=n;
		A=new int [n];
	}
	~Diagonal () // since we are creating memory in heap so for realissing memory we will use destructor 
	{
		delete []A;
	}
	void Set (int i, int j, int x);
	int Get (int i, int j);
	void Display();
};
void Diagonal::Set(int i,int j,int x)
{
	if (i==j)
	A[i-1]=x;
}
int Diagonal::Get(int i,int j)
{
	if (i==j)
	{
		return A[i-1];
		
	}
	else return 0;
}
void Diagonal::Display()

{
for (int i=0;i<n;i++)
{
	for (int j=0;j<n;j++)
	{
		if (i==j)
		cout << A[i]<<" ";
		else 
		cout<<"0 ";
	}
	cout<<endl;
}
}

int main ()

{
	Diagonal d(4);
	d.Set(1,1,5);
	d.Set(2,2,9);
	d.Set(3,3,7);
	d.Set(4,4,2);
	d.Display();
	return 0;
}
