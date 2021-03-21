#include<iostream>
using namespace std;
struct Array {
	int* A;
	int size;
	int length;
};

int Min(struct Array* arr) {
	int min = INT_MAX;
	for (int i = 0; i < arr->length; i++) {
		if (arr->A[i] < min)
			min = arr->A[i];
	}
	return min;
}

int Max(struct Array* arr) {
	int max = INT_MIN;
	for (int i = 0; i < arr->length; i++)
		if (arr->A[i] > max)
			max = arr->A[i];
	return max;
}

void Count_Find_duplicate_hash(struct Array* arr) {
	int* H;
	H = new int[Max(arr)]{ 0 };
	for (int i = 0; i < Max(arr); i++)
		H[i] = { 0 };
	for (int i = 0; i < arr->length; i++)
		H[arr->A[i]]++;
	for (int i = Min(arr); i <= Max(arr); i++) {
		if (H[i] > 1)
			cout << i << " is duplicate element and appering for " << H[i] << " Times"<<endl;
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
	
	Count_Find_duplicate_hash(&arr);


	// Display(arr);
	return 0;

}


















//  ---------------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;
int main ()
{
	int i;
	int A[15]={1,2,4,5,6,7,8,8,8,8,9,10,10,10};
	int H[15]={0}; // Creating A hash table of as all elements As zero 
	
	for (i=0;i<15;i++) // ----------- n
	{
		H[A[i]]++;
	}
	for (i=0;i<15;i++) // ----------------n = n+n=2n
	{
		if (H[i]>1)
		cout<<i<<" Is appeaaring "<<H[i]<<" Times"<<endl;
		
	}
	
	return 0;
	
}
// Time Complexity is O(n)
