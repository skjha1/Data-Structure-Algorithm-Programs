// find out the average

#include <iostream>
using namespace std;
int main()
{
	int arr[10];
	float sum = 0;
	float avg;
	int no;
	cin >> no;
	/* We are using a for loop to traverse through the array
	 * while storing the entered values in the array
	 */
	for (int i = 0; i < no; i++)
	{
		cout << "Enter the pos " << i + 1 << endl;
		cin >> arr[i];
	}
	for (int i = 0; i < no; i++) {
		sum = sum + arr[i];
		
	}
	avg = sum / no;
	cout << endl;
	cout <<"The avg of all the number is "<< avg;
	return 0;
}