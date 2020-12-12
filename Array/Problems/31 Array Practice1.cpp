#include <iostream>
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
	cout << "The elements of the array is " << endl;
	for (i = 0; i < arr->length; i++)
		cout << arr->A[i]<<" ";
}

void Append(struct Array* arr, int val)
{
	arr->A[arr->length] = val;
	arr->length++;
}

void Insert(struct Array* arr, int index, int val)
{
	int i;
	for (i = arr->length; i > index; i--)
		arr->A[i] = arr->A[i - 1];
	arr->A[index] = val;
	arr->length++;
}

void Delete(struct Array* arr, int index)
{
	int x;
	x = arr->A[index];
	for (int i = index; i < arr->length; i++)
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

// Binary Search is only applicable on sorted Array 

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
	if (l <= h)
	{
		int mid = 0;
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

int Get(struct Array* arr, int index )
{
	if (index >= 0 && index < arr->length)
		return arr->A[index];
	else
		return -1;
}

void Set(struct Array* arr, int index, int val)
{
	if (index >= 0 && index < arr->length)
		arr->A[index] = val;
}

int Min(struct Array* arr)
{
	int min = arr->A[0];
	for (int i = 0; i < arr->length; i++)
	{
		if (arr->A[i] < min)
			min = arr->A[i];
	}
	return min;
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
	int avg;
	int sum = 0;
	for (int i = 0; i < arr->length; i++)
	{
		sum += arr->A[i];
	}
	avg = sum / arr->length;
	return avg;
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
	for (i = 0, j = arr->length-1 ; i < j; i++, j--)
		Swap(&arr->A[i], &arr->A[j]);
}

// Insert element in the array at sorted position 

void Insert1(struct Array* arr,int val)
{
	int i;
	i = arr->length - 1;
	while (arr->A[i] > val)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = val;
	arr->length++;
}

int ISsorted(struct Array* arr)
{
	int i;
	for (i = 0; i < arr->length-1; i++)
	{
		if (arr->A[i] > arr->A[i + 1])
			return 0;
	}
	return 1;

}

void BubbleSort(struct Array* arr)
{
	int i, j;
	int flag = 0;
	for (i = 0; i < arr->length - 1; i++) // for pass 
	{
		flag = 0;
		for (j = 0; j < arr->length - 1-i; j++) // for comp
		{
			if (arr->A[j] > arr->A[j + 1])
			{
				Swap(&arr->A[j], &arr->A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void Insertionsort(struct Array* arr)
{
	int i, j, x;
	for (i = 1; i < arr->length; i++)
	{
		j = i - 1;
		x = arr->A[i];
		while (j > -1 && arr->A[j] > x)
		{
			arr->A[j + 1] = arr->A[j];
			j--;
		}
		arr->A[j + 1] = x;
	}
}

int main()
{
	struct Array arr;
	cout << "Enter the size of the array " << endl;
	cin >> arr.size;
	arr.A = new int[arr.size];
	int no;
	cout << "Enter the length of the array" << endl;
	cin >> no;
	arr.length = 0;
	cout << "Enter the elements of the Aarray " << endl;
	for (int i = 0; i < no; i++)
		cin >> arr.A[i];
	arr.length = no;

	Display(&arr);

	/*cout <<endl<< "Elements after appending " << endl;
	Append(&arr, 8);
	Display(&arr);
	cout <<endl<< "Elements after Inserting " << endl;
	Insert(&arr, 4, 18);
	Display(&arr);
	cout <<endl<< "Elements after Deleting " << endl;
	Delete(&arr, 3);
	Display(&arr);*/

	//cout <<endl<< "The element is at index " << LS(&arr, 6)<<endl;
	//cout << "The element is at index " << ILS(&arr, 1500)<<endl;
	//cout <<endl<< "The element is at index " << BS(&arr,0,arr.length, 1500)<<endl;
	//cout <<endl<< "The element is at index " << RBS(&arr,0,arr.length, 1500)<<endl;

	//cout << endl<<"Element at the given position is "<< Get(&arr, 2);
	//Set(&arr, 3, 800);
	//cout << endl;
	//Display(&arr);
	//cout << endl << "Max elemet in the array is " <<Max(&arr)<< endl;
	//cout  << "Min elemet in the array is " <<Min(&arr)<< endl;
	//cout  << "Addtion of the array is " <<Sum(&arr)<< endl;
	//cout << "Average of the array is " <<Avg(&arr)<< endl;

	///*Reverse(&arr);
	//cout << endl;
	//Display(&arr);*/
	//Reverse1(&arr);
	//cout << endl;
	//Display(&arr);


	/*Insert1(&arr, 8);
	cout << endl;
	cout << "Elemet after inserted at sorted position ";
	Display(&arr);*/

	/*int s = ISsorted(&arr);
	if (s== 1)
		cout <<endl<< "Sorted";
	else
		cout <<endl<< "Not Sorted";*/

	/*BubbleSort(&arr);
	cout << endl;
	Display(&arr);*/
	
	//Insertionsort(&arr);
	//cout << endl;
	//Display(&arr);


	return 0;
}
