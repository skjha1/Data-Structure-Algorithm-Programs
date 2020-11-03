#include <iostream>
using namespace std;
int main()
{
	int A[6] = { 1,2,3,4,4,5 };
	int* p;
	int i;
	p = new int[4]; // dynamically created memory 
	p[0] = 1; p[1] = 2; p[2] = 3; p[3] = 9;
	for (i = 0; i < 6; i++)
		cout << A[i]<<" ";
	cout << endl;
	for (i = 0; i < 4; i++) {
		
		cout << p[i] << " ";
	}
	return 0; 

}