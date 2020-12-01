
#include <iostream>
using namespace std;
struct Array
{
	int* A;
	int size;
	int length;
};

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Display(struct Array *arr)
{
	int i;
	cout << "The elements of array is " << endl;
	for (i = 0; i < arr->length; i++)
		cout<<arr->A[i]<<" ";

}
void append(struct Array *arr, int val)
{
	arr->A[arr->length] = val;
	arr->length++;
}
void insert(struct Array* arr, int index, int val)
{
	int i;
	for (i = arr->length; i > index; i--)
		arr->A[i] = arr->A[i - 1];
	arr->A[index] = val;
	arr->length++;

}
void Delete(struct Array* arr, int index)
{
	int i;
	int x;
	 x=arr->A[index];
	for (i = index; i < arr->length; i++)
		arr->A[i] = arr->A[i + 1];
	arr->length--;
}

int LinearSearch(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
			return i;
	}
	return -1;
}
// improvin linear search 

int ILinearsearch(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i]) {
			swap(&arr->A[i], &arr->A[0]);
			return i;
		}
		
	}
}

int BinarySearch(struct Array* arr, int l, int h, int key)
{
	int mid; 
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int RBinarysearch(struct Array* arr, int l, int h, int key)
{
	int mid = 0;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			return RBinarysearch(arr, l, mid - 1, key);
		else
			return RBinarysearch(arr, mid + 1, h, key);
	}
	return -1;

}

int Get(struct Array* arr, int index )
{
	if (index > 0 && index < arr->length)
		return arr->A[index];
	else
		return -1;

}
int set(struct Array* arr, int index, int val)
{
	if (index > 0 && index < arr->length)
		arr->A[index] = val;
	return 0;

}

int Max(struct Array* arr)
{
	int max = arr->A[0];
	for (int i = 0; i < arr->length; i++)
	{
		if (max < arr->A[i])
			max = arr->A[i];
	}
	return max;
}int min(struct Array* arr)
{
	int min = arr->A[0];
	for (int i = 0; i < arr->length; i++)
	{
		if (min > arr->A[i])
			min = arr->A[i];
	}
	return min;
}

int Sum(struct Array *arr)
{
	int sum = 0;
	for (int i = 0; i < arr->length; i++)
	{
		sum += arr->A[i];
	}
	return sum;
}

int Avg(struct Array *arr)
{
	int avg;
	int sum = 0;
	for (int i = 0; i < arr->length; i++) {
		sum += arr->A[i];
		
	}
	avg = sum / arr->length;
	return avg; 


}

int main()
{
	struct Array arr;
	cout << "Enter the size of Array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	int no;
	cout << "Enter the length of Array " << endl;
	cin >> no;
	arr.length = 0;
	cout << "Enter the elements of the array " << endl;
	for (int i = 0; i < no; i++)
		cin >> arr.A[i];
	arr.length = no;
	Display(&arr);

	//append(&arr, 9);
	//cout<<endl << " Array after appending is " << endl;
	//Display(&arr);
	//
	//insert(&arr, 2, 16);
	//cout <<endl<< " Array after inserting is " << endl;
	//Display(&arr);

	//Delete(&arr, 2);
	//cout <<endl<< "Array After del element is " << endl;
	//Display(&arr);


	//cout<<endl<<"The element is present at position "<<LinearSearch(&arr, 5)<<endl;

	//cout << endl << "The element is present at position " << ILinearsearch(&arr, 3) << endl;

	//cout << endl << "The element is present at the pos " << BinarySearch(&arr, 0, arr.length-1, 8);

	//cout << endl << " The element is present at the pos " << RBinarysearch(&arr, 0, arr.length-1, 8);
	/*printf("The element at particular position is %d\n", Get(&arr, 2));
	set(&arr, 2, 15);
	Display(&arr);*/
	/*cout << "The max is " << Max(&arr) << endl;*/
	/*cout << "The min is " <<min(&arr) << endl;*/
	//cout << "The sum of the array is " << Sum(&arr) << endl;
	cout << " The avg of the array is " << Avg(&arr) << endl;
	return 0;

}
