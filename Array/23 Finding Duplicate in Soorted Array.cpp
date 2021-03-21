#include<iostream>
using namespace std;
struct Array {
	int* A;
	int size;
	int length;
};

void Find_Duplicate(struct Array* arr) {
	int last_duplicate = 0;// initially set duplicate as zero
	for (int i = 0; i < arr->length; i++) { // iterate through the list of elements 
		if (arr->A[i] == arr->A[i + 1] && arr->A[i] != last_duplicate) // if consequtive elements are equal then consider as duplicate
		{
			cout << arr->A[i]<<" ";
			last_duplicate = arr->A[i]; // everytine after printing duplicate update it will next duplicate element
		}
	}
}

int main() {
	struct Array arr;
	int no;
	cout << "Enter the size of the array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	arr.length = 0;
	cout << "Enter the size of the array" << endl;
	cin >> no;
	cout << "Enter the elements of the array " << endl;
	for (int i = 0; i < no; i++) 
		cin >> arr.A[i];
	arr.length = no;
	cout << "The duplicate elements are ! " << endl;
	Find_Duplicate(&arr);
	return 0;

}













//   -------------------------------------------------------------------------------------------------------------------------------------------
#include<iostream>
using namespace std;
int main ()
{
	int A[10]={3,6,8,8,10,12,15,15,15,20};
	int lastduplicate=0;
	int i,no=10;
	
	cout<<"Duplicate Elements are "<<endl;
	for (i=0;i<no;i++)
	{
		if (A[i]==A[i+1] && A[i]!=lastduplicate)
		{
			cout<<" "<<A[i];
			lastduplicate=A[i];
		}
	}
	return 0;
	
}
