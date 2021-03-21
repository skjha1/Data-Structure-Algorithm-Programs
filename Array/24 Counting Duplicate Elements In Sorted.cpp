#include<iostream>
using namespace std ;

struct Array {
	int* A;
	int size;
	int length;
};

void Count_Find_duplicate(struct Array* arr) {
	int i;
	for (i = 0; i < arr->length - 1; i++) {
		if (arr->A[i] == arr->A[i + 1]) // if the consequtive term of the array is equal 
		{
			int j = i + 1; // set j one next to i and increment as long as both are equal
			while (arr->A[j] == arr->A[i]) j++;
			cout << arr->A[i] << " is duplicate element and appering for " << j - i << " Times";// j-i will give total number of duplicate element 
			i = j - 1; // set i before one before j 
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
	Count_Find_duplicate(&arr);


	// Display(arr);
	return 0;

}
// Time complexity is O(n) 
// Here while loop is negligible as compared to for loop

//   --------------------------------------------------------------------------------------------------------------------------------------------------------------


#include<iostream>
using namespace std ;
int main ()
{
	int i,j;
	int A[13]={3,6,8,8,8,10,12,12,12,15,20,20,20};
	
	for(i=0;i<13;i++)
	{
		if (A[i]==A[i+1])
		{
			j=i+1;
			while (A[j]==A[i])
			j++;
			cout<<A[i]<<" Appering "<<j-i<<" Times "<<endl;
			i=j-1;
		}
	}
	cout<<endl;
	return 0;
}
// Time complexity is O(n) 
// Here while loop is negligible as compared to for loop
