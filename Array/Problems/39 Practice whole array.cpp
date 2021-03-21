#include<iostream>
using namespace std;
struct Array {
	int* A;
	int size;
	int length;
};

void Swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Display(struct Array arr) {
	cout << "The elements of the array is !" << endl;
	for (int i = 0; i < arr.length; i++)
		cout << arr.A[i]<<" ";
}

void Append(struct Array *arr, int x) {
	if (arr->length < arr->size) {
		arr->A[arr->length] = x;
		arr->length++;
	}
}

void Insert(struct Array* arr, int index, int val) {
	for (int i = arr->length; i > index; i--)
		arr->A[i] = arr->A[i - 1];
	arr->A[index] = val;
	arr->length++;
}

void Delete(struct Array* arr, int index) {
	int x = arr->A[index];
	for (int i = index; i < arr->length - 1; i++)
		arr->A[i] = arr->A[i + 1];
	arr->length--;
}

int L_Search(struct Array* arr, int  key) {
	for (int i = 0; i < arr->length; i++) {
		if (key == arr->A[i])
			return i;
	}
	return -1;
}

int Improved_L_Search(struct Array* arr, int key) {
	for (int i = 0; i < arr->length; i++) {
		if (key == arr->A[i]) {
			Swap(&arr->A[0], &arr->A[i]);
			return i;
		}

	}
	return -1;
}

int Binar_search(struct Array* arr, int key)
{
	int l = 0;
	int r = arr->length - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int R_B_Search(struct Array* arr, int low, int high, int key) {
	if (low < high) {
		int mid = low + high / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			return R_B_Search(arr, low, mid - 1, key);
		else
			return R_B_Search(arr, mid + 1, high, key);
	}
	return -1;
}

int Get(struct Array* arr, int index) {
	if (arr->length < arr->size) {
		return arr->A[index];
	}
}

void Set(struct Array* arr, int index, int val) {
	if (arr->length < arr->size) {
		arr->A[index] = val;
	}
}

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

int Count(struct Array* arr) {
	int count = 0;
	for (int i = 0; i < arr->length; i++) {
		count++;
	}
	return count;
}

int Sum(struct Array* arr) {
	int sum = 0;
	for (int i = 0; i < arr->length; i++)
		sum += arr->A[i];
	return sum;
}

int Avg(struct Array* arr) {
	return Sum(arr) / Count(arr);
}

void Reverse1(struct Array* arr) {
	int* B;
	int j;
	B = new int[arr->length];
	for (int i = arr->length-1,j=0; i>=0; i--,j++)
	{
		B[j] = arr->A[i];
	}
	for (int i =0; i <arr->length; i++)
	{
		arr->A[i] = B[i];
	}
}

void Reverse2(struct Array* arr) {
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
		Swap(&arr->A[i], &arr->A[j]);
}

void Insert(struct Array* arr, int val) {
	int i = arr->length-1;
	while(arr->A[i] > val) {
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = val;
	arr->length++;
}

bool IsSorted(struct Array* arr) {
	for (int i = 0; i < arr->length - 1; i++) {
		if (arr->A[i] > arr->A[i + 1])
			return false;
	}
	return true;
}

void Arragenegetive(struct Array* arr) {
	int i = 0;
	int j = arr->length - 1;
	while (i < j) {
		while (arr->A[i] < 0) { i++; }
		while (arr->A[j] > 0) { j--; }
		if (i < j)
			Swap(&arr->A[i], &arr->A[j]);
	}
}

void SingleMissingElement(struct Array* arr) {
	int sum = 0;
	int n = arr->A[arr->length-1]; // this denotes the last element of the array
	for (int i = 0; i < arr->length; i++)
	{
		sum += arr->A[i]; // sum of the existing array 
	}
	// (n*(n+1))/2 ----> Gives the total sum upto that number 
	int target = (n * (n + 1)) / 2- sum;
	cout << "The missing number is " << target;

}

// another method for finding the missing number

void SingleMissingNumber1(struct Array* arr) {
	int low = arr->A[0]; // take the 1st element of the array 
	int difference = low - 0;// the difference should be constant if not then add the index & diffence to get missing number 
	
	for (int i = 0; i < arr->length; i++)
	{
		if (arr->A[i] - i != difference) {
			cout << "Missing element is " << i + difference;
			break;
		}

	}
}

void MultipleMissingElement(struct Array* arr) {
	int low = arr->A[0];
	int difference = low - 0;
	for (int i = 0; i < arr->length; i++) {
		if (arr->A[i] - i != difference) {
			while (difference < arr->A[i] - i)
			{
				cout << i + difference<<" ";
				difference++;
			}
		}
	}
}


// this is for the unsorted array 
void Missingelemet_Hash_table(struct Array* arr) {
	int* H;
	int i;
	int low = Min(arr);
	int high = Max(arr);
	H = new int[high];
	for (int i = 0; i < high; i++)H[i] = { 0 };
	for (i = 0; i < arr->length-1; i++) {
		H[arr->A[i]]++;
	}
	for (i = Min(arr); i <= high; i++) {
		if (H[i] == 0)
			cout << i<<" ";
	}
}

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

// Finding duplicate for unsorted array 
void Count_duplicate_unsorted(struct Array* arr) {
	
	for (int i = 0; i < arr->length - 1; i++) {
		int count = 1; // intializing count as 1 
		if (arr->A[i] != -1) { // if element is already checkd then dont go for checking the elements
			for (int j = i + 1; j < arr->length; j++)
			{
				if (arr->A[i] == arr->A[j]) // if duplicate element is found 
				{
					count++; // increament the count 
					arr->A[j] = -1; // and mark element as -1 so that next time it won't confuse 
				}
			}
			if (count > 1) // if count is greater then i.e there is duplicate element
				cout << arr->A[i] << " is appearing for " << count << " Times" << endl;
		}
	}
}

void Count_duplicate_unsorted_hash(struct Array* arr) {
	int low = Min(arr);
	int high = Max(arr);
	int* H;
	H = new int[high];;
	for (int i = 0; i < high; i++) H[i]={ 0 }; // initialise hash table with zero
	for (int i = 0; i < arr->length; i++) 
		H[arr->A[i]]++; // for every element go to that particular index and make increment everytime 
		for (int i = low; i <= high; i++) // traverse through the whole hash table and check the elements 
		{

			if (H[i] > 1) // if hash table elements is greater then 1 that is there is the duplicate element in the array 
				cout << i << " is appearing for " << H[i] << " Times" << endl; // print the duplicate and also print its frequency
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

	// Append(&arr, 5);
	//Insert(&arr, 2, 7);
	// Delete(&arr, 2);

	//cout <<"The element is present at the index "<<L_Search(&arr, 5)<<endl;
	//cout <<"The element is present at the index "<< Improved_L_Search(&arr, 5)<<endl;
	//cout <<"The element is present at the index "<< Binar_search(&arr, 60)<<endl;
	//cout <<"The element is present at the index "<< R_B_Search(&arr, 0,arr.length-1,80)<<endl;

	//cout <<"The element at the index is "<< Get(&arr, 2)<<endl;
	//Set(&arr, 6, 55);
	/*cout << "The minimum element in the array is " << Min(&arr)<<endl;
	cout << "The maximum element in the array is " << Max(&arr)<<endl;
	cout << "Total number of element in the array is " << Count(&arr)<<endl;
	cout << "Total number of element in the array is " << Sum(&arr)<<endl;
	cout << "Total number of element in the array is " << Avg(&arr)<<endl;*/

	//Reverse1(&arr);
	//Reverse2(&arr);

	//Insert(&arr, 87);

	/*if (IsSorted(&arr) == 0)
		cout << "Array is not sorted" << endl;
	else
		cout << "Array is sorted" << endl;*/

	//Arragenegetive(&arr);

	// SingleMissingElement(&arr);
	//SingleMissingNumber1(&arr);

	/*cout << "The missing elements are ! " << endl;
	MultipleMissingElement(&arr);*/

	 //Missingelemet_Hash_table(&arr);

	/*cout << "The duplicate elements are ! " << endl;
	Find_Duplicate(&arr);*/
	//Count_Find_duplicate(&arr);

	 //Count_Find_duplicate_hash(&arr);

	//Count_duplicate_unsorted(&arr);

	Count_duplicate_unsorted_hash(&arr);


	// Display(arr);
	return 0;

}
