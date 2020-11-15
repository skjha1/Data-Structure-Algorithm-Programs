// Find the min and max from an array

#include<iostream>
using namespace std;
int main()
{
	int A[10], no, i;
	cout<< "Enter the size of Array";
	cin >> no;
	cout << "Enter all the elements of the array";
	for (i = 0; i < no; i++)
		cin >> A[i];
	int max = A[0];
	for (i = 0; i < no; i++)
	{
		if (max < A[i])
			max = A[i];
	}
	int min = A[0];
	for (i = 0; i < no; i++)
	{
		if (min > A[i])
			min = A[i];
	}
	cout << "Max is " << max << endl;
	cout << "Min is " << min << endl;
	return 0;
	
}


------------------------------------------------------------------------------------
//method 2

#include<iostream>
using namespace std;




int maximum(int A[],int size) {
		int i,max=A[0];
		for (i = 0; i < size; i++)
		{
			if (max < A[i])
				max=A[i];

		}
		cout << "Max is " << max<<endl;
		return 0;
	}
int minimum(int A[],int size) {
		int i,min=A[0];
		for (i = 0; i < size; i++)
		{
			if (min > A[i])
				min=A[i];

		}
		cout << "Min is " << min<< endl;
		return 0;
	}


int main()
{
	int A[10], no;
	int i;
	cout << "Enter size of Array"<<endl;
	cin >> no;
	cout << "Enter Elements of array"<<endl;
	for (i = 0; i < no; i++)
		cin >> A[i];
	maximum(A, no);
	minimum(A, no);
	return 0;
	
}

----------------------------------------------------------------------------------

#include<iostream>
using namespace std;
struct Pair {
	int min;
	int max;
};

struct Pair Getminmax(int A[], int size)
{
	struct Pair minmax;
	if (size == 1)// if there is only one elements 
	{
		minmax.max = A[0];
		minmax.min = A[0];
		return minmax;
	}
	// If there are more than one elements,
	// then initialize min and max
	if (A[0] > A[1])
	{
		minmax.max = A[0];
		minmax.min = A[1];
	}
	else 
	{
		minmax.max = A[1];
		minmax.min = A[0];
	}
	for (int i = 2; i < size; i++)
		{
			if ( A[i]<minmax.max)
				minmax.max = A[i];
			else if ( A[i]> minmax.min )
				minmax.min = A[i];
		}
	return minmax;
}
int main()
{
	int A[10], no;
	int i;
	cout << "Enter size of Array"<<endl;
	cin >> no;
	cout << "Enter Elements of array"<<endl;
	for (i = 0; i < no; i++)
		cin >> A[i];
	struct Pair minmax = Getminmax(A, no);
	cout << "Max is " << minmax.min<<endl;
	cout << "Min is " << minmax.max << endl;
	return 0;
	
}
