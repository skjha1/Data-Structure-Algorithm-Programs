#include <iostream>
using namespace std;
struct Array
{
	int *A;
	int size;
	int length;
};

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Display(struct Array* arr)
{
	int i;
	cout << "The elements of the array is " << endl;
	for (i = 0; i < arr->length; i++)
		cout << arr->A[i]<<" ";
}

void Append(struct Array* arr,int val)
{
	arr->A[arr->length] = val;
	arr->length++;
}
void Insert(struct Array* arr, int index, int val)
{
	int i;
	if (index < arr->length && index > 0)
	{
		for (i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = val;
		arr->length++;
	}
}

void Delete(struct Array* arr, int index)
{
	int i, x;
	x = arr->A[index];
	for (i = index; i < arr->length; i++)
		arr->A[i] = arr->A[i + 1];
	arr->length--;

}

int LS(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
			return i;
	}
	return -1;
}

int ILS(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i]) {
			Swap(&arr->A[i], &arr->A[0]);
			return i;
		}

	}
	return -1;
}

int BS(struct Array* arr, int key)
{
	int mid;
	int low = 0;
	int high = arr->length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int RBS(struct Array* arr, int low, int high, int key)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			return RBS(arr, low, mid - 1, key);
		else
			return RBS(arr, mid + 1, high, key);
	}
}

void Set(struct Array* arr,int index , int val)
{
	if (index < arr->length && index >= 0)
	{
		arr->A[index] = val;
	}
}

int Get(struct Array* arr, int index)
{
	if (index >= 0 && index < arr->length)
		return arr->A[index];
	else
		return -1;
}

int Max(struct Array* arr)
{
	int Max = arr->A[0];
	for (int i = 0; i < arr->length; i++)
		if (Max < arr->A[i])
			Max = arr->A[i];
	return Max;
}

int Min(struct Array* arr)
{
	int Min = arr->A[0];
	for (int i = 0; i < arr->length; i++)
		if (Min > arr->A[i])
			Min = arr->A[i];
	return Min;
}

int Sum(struct Array* arr)
{
	int sum = 0;
	for (int i = 0; i < arr->length; i++)
	{
		sum += arr->A[i];
	}
	return sum;
}

int Avg(struct Array* arr)
{
	return Sum(arr) / arr->length;
}

void Reverse(struct Array* arr)
{
	int* B;
	B = new int[arr->size];
	int i, j;
	for (int i = arr->length-1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->A[i];
	}
	for (int i = 0; i <= arr->length; i++)
	{
		arr->A[i] = B[i];
	}
}

void Reverse1(struct Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		Swap(&arr->A[i], &arr->A[j]);
	}
}

void Insert_at_sorted(struct Array* arr, int val)
{

	int i = arr->length - 1;
	if (arr->length == arr->size) return;

	while (i>=0 && arr->A[i] > val)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = val;
	arr->length++;
}

int IsSorted(struct Array* arr)
{
	int i;
	for (i = 0; i < arr->length-1; i++)
	{
		if (arr->A[i] < arr->A[i + 1])
			return 0;
	}
	return 1;
}

void Arrange(struct Array* arr)
{
	int i = 0;
	int j = arr->length-1;
	while (i < j)
	{
		while (arr->A[i] < 0) { i++; }
		while (arr->A[j] >= 0) { j--; }
		if (i < j)
			Swap(&arr->A[i], &arr->A[j]);
	}
}

Array* Merge(struct Array* arr1, struct Array* arr2)
{
	Array* A = new Array;
	int n = arr1->length + arr2->length;
	A->A = new int[n];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			A->A[k++] = arr1->A[i++];
		A->A[k++] = arr2->A[j++];
	}
	for (; i < arr1->A[i]; i++)
		A->A[k++] = arr1->A[i];
	for (; i < arr2->A[j]; j++)
		A->A[k++] = arr2->A[j];
	A->length = k;
	return A;
}

Array* Union(struct Array* arr1, struct Array* arr2)
{
	Array* A = new Array;
	int n = arr1->length + arr2->length;
	A->A = new int[n];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			A->A[k++] = arr1->A[i++];
		else if (arr2->A[j]< arr1->A[i])
			A->A[k++] = arr2->A[j++];
		else {
			A->A[k++] = arr1->A[i++];
			j++;
		}
	}
	for (; i < arr1->A[i]; i++)
		A->A[k++] = arr1->A[i];
	for (; i < arr2->A[j]; j++)
		A->A[k++] = arr2->A[j];
	A->length = k;	
	return A;
}


Array* Intersection(struct Array* arr1, struct Array* arr2)
{
	Array* A = new Array;
	int n = arr1->length + arr2->length;
	A->A = new int[n];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else {
			A->A[k++] = arr1->A[i++];
			j++;
		}
	}
	A->length = k;	
	return A;
}


Array* Difference(struct Array* arr1, struct Array* arr2)
{
	Array* A = new Array;
	int n = arr1->length + arr2->length;
	A->A = new int[n];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			A->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else {
			i++;
			j++;
		}
	}
	for (; i < arr1->length; i++)
		A->A[k++] = arr1->A[i];
	A->length = k;
	return A;
}



int main()
{
	struct Array arr;
	struct Array arr1;
	struct Array* arr2;

	int no, i, no1;
	cout << "Enter the size of the array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	cout << "Enter the length of the array " << endl;
	cin >> no;
	arr.length = 0;
	cout << "Enter the elements of the array" << endl;
	for (i = 0; i < no; i++)
	{
		scanf_s("%d", &arr.A[i]);
	}
	arr.length = no;

	cout << "Enter the Size of the 2nd array " << endl;
	cin >> arr1.size;
	arr1.A = new int[arr1.size];
	cout << "Enter the length of the array " << endl;
	cin >> no1;
	arr1.length = 0;
	cout << "Enter the elements of the array " << endl;
	for (i = 0; i < no1; i++)
	{
		scanf_s("%d", &arr1.A[i]);
	}
	arr1.length = no1;


	//arr2->A = new int[no2];

	/*Append(&arr, 8);*/
	/*Insert(&arr, 2, 6);*/
	//Delete(&arr, 4);


	//cout <<"The element is present at the index "<< LS(&arr, 10)<<"th In the array "<<endl;
	//cout <<"The element is present at the index "<< ILS(&arr, 10)<<"th In the array "<<endl;
	//cout <<"The element is present at the index "<< BS(&arr, 10)<<"th In the array "<<endl;
	//cout <<"The element is present at the index "<< RBS(&arr, 0,arr.length,54)<<"th In the array "<<endl;
	//cout << "The max  number of the Array is " << Max(&arr) << endl;
	//cout << "The min  number of the Array is " << Min(&arr) << endl;
	//cout << " The Sum of the Number is " << Sum(&arr) << endl;
	//cout<<" The Average of the Number is " << Avg(&arr)<<endl;

	// Reverse(&arr);
	/*Reverse1(&arr);*/

	/*Insert_at_sorted(&arr, 8);*/

	/*if (IsSorted(&arr) == 0)
		cout << "Array Is not sorted " << endl;
	else
		cout << "Array is  sorted " << endl;*/

	/*Arrange(&arr);*/



	//arr2 = Merge(&arr, &arr1);
	//Display(arr2);

	/*arr2 = Union(&arr, &arr1);
	Display(arr2);*/
	
	
	/*arr2 = Intersection(&arr, &arr1);
	Display(arr2);*/
	
	arr2 = Difference(&arr, &arr1);
	Display(arr2);


	return 0;
}
