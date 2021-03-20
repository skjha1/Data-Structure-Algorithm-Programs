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
	Reverse2(&arr);

	Display(arr);
	return 0;

}
