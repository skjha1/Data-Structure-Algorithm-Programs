#include<iostream>
using namespace std;

struct Array
{
	int* A;
	int size;
	int length;
};
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Display(struct Array* arr)
{
	int i;
	cout << "the elements of the array is " << endl;
	for (i = 0; i < arr->length; i++)
		cout <<arr->A[i] << " ";
}

void Append(struct Array* arr, int val)
{
	arr->A[arr->length] = val;
	arr->length++;
}
void Insert(struct Array* arr, int index , int val )
{
	int i;
	for (i = arr->length; i > index; i--)
		arr->A[i] = arr->A[i - 1];
	arr->A[index] = val;
	arr->length++;
}
void Del(struct Array* arr, int index)
{
	int i;
	int x;
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
int BS(struct Array* arr, int l, int h, int key)
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

int RBS(struct Array* arr, int l, int h, int key)
{
	int mid;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			return RBS(arr, l, mid - 1, key);
		else
			return RBS(arr, mid + 1, h, key); 
	}
	return -1;
} 

void Reverse(struct Array* arr)
{
	int i, j; 
	int* B; 
	B = new int[arr->size];
	for (i = arr->length-1, j = 0; i >= 0; i--, j++)
		B[j] = arr->A[i];
	for (i = 0; i < arr->length; i++)
		arr->A[i] = B[i];
	
}
void Reverse1(struct Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
		Swap(&arr->A[i], &arr->A[j]);

}
void Insert1(struct Array* arr, int val)
{
	int i;
	i = arr->length - 1;
	if (arr->length == arr->size) return;
	while (i>=0 && arr->A[i] > val) // here we dont know how many times we have to repeat the loop so we used while loop 
	{
		arr->A[i + 1] = arr->A[i]; // go on shifting the elements value is less then array's elements 
		i--;
	}
	arr->A[i + 1] = val; // set the value at a given pos
	arr->length++;
}

int IsSorted(struct Array* arr)
{
	for (int i = 0; i < arr->length - 1; i++) 
	{
		if (arr->A[i] > arr->A[i + 1]) // if 1st element is greater then 2nd element then it will k/as not sorted so return 0 
			return 0;
	}
	
	return 1; // if everything is ok and the element came successfully out of loop means it is sorted return 1 for thet 
}

void Arrange(struct Array* arr)
{
	int i=0;
	int j = arr->length - 1; // set j to the last of the array element
	while (i < j) {
		while (arr->A[i] < 0) { i++; } //while the array element is less then zero keep increamenting the array
		while (arr->A[j] >= 0) { j--; } //  while the array elemet is greater then zero decreamenting the array from last 
		if (i < j) // and when i is less then j interchange the value 
			Swap(&arr->A[i], &arr->A[j]);
	}
	// time taken is O (n) -- > comparing the elemets total n+2 elements compared 
}




int main()
{
	struct Array arr;
	cout << "Enter the size of Array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];	
	int no;
	cout << "Enter the length of the array " << endl;
	cin >> no;
	arr.length = 0;	
	cout << "Enter the elements of the array " << endl;
	for (int i = 0; i < no; i++)
		cin >> arr.A[i];
	arr.length = no;
	Display(&arr);
	/*Append(&arr,8);*/
	/*Insert(&arr, 2, 6);*/
	/*Del(&arr, 2);*//*
	cout << endl;
	cout << BS(&arr,0,arr.length-1, 5);*/
						
	/*Display(&arr);*/
	/*Reverse1(&arr);
	cout << endl;*/
	//Reverse1(&arr);
	/*Insert1(&arr, 18);*/
	cout << endl;
	/*cout<<IsSorted(&arr);*/
	/*Arrange(&arr);*/

	Display(&arr);
	


	return 0;
}
