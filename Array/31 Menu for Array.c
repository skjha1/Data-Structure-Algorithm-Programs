#include<stdio.h>
#include<stdlib.h>

struct array 
{
	int *A;
	int size;
	int length;
};


void Display(struct array arr);
void Append(struct array *arr,int x);
void Insert(struct array *arr,int index,int x);
void Delete(struct array *arr,int index);
void swap(int*p,int*q);
void LinearSearch(struct array *arr,int key);
void LinearSearchSwapToPrev(struct array *arr,int key);
void LinearSearchSwapToHead(struct array *arr,int key);
void BinSearch(struct array *arr,int key);
void RevBinSearch(struct array arr,int low,int high,int key);
void Get(struct array arr,int index);
void Set(struct array *arr,int index,int x);
void Max(struct array arr);
void Min(struct array arr);
int Sum(struct array arr);
float Avg(struct array arr);
void Rev1(struct array *arr);
void Rev2(struct array *arr);
void Display(struct array arr);
void lShift(struct array *arr);
void rShift(struct array *arr);
void lRot(struct array *arr);
void rRot(struct array *arr);
void InsertSort(struct array *arr,int x);
void IsSort(struct array arr);
void Arrange(struct array *arr);
struct array* Merge(struct array *arr,struct array *arr2);



// All the functions are here->>>>

//Swap Function
void swap(int*p,int*q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}

//Display Function
void Display(struct array arr)
{
	int i;
	printf("The elements in the array are: \n");
	for(i=0;i<arr.length;i++)
	{
		printf("%d ",arr.A[i]);
	}
	printf("\n");
}

//Append Function
void Append(struct array *arr,int x)
{
	int i;
	if(arr->length<arr->size)
	{
		arr->A[arr->length]=x;
		arr->length++;
	}
	else
	{
		printf("The array has no empty space to append");
	}
}

//Insert Function
void Insert(struct array *arr,int index,int x)
{
	int i;
	if(arr->length<arr->size)
	{
	if(index>=0 && index<=arr->length)
	{
		for(i=arr->length;i>index;i--)
		{
			arr->A[i]=arr->A[i-1];
		}
		arr->A[index]=x;
		arr->length++;
	}
	else
	{
		printf("You cannot insert the value due to the invalid index. \n");
	}
    }
    else
    {
    	printf("The size is not sufficient to insert the element in the array.\n");
	}
}

//Delete Function
void Delete(struct array *arr,int index)
{
	int i;
		if(index>=0 && index<=arr->length)
		{
			for(i=index;i<arr->length;i++)
			{
				arr->A[i]=arr->A[i+1];
			}
			arr->length--;
		}
		else
		{
			printf("You can delete the element due to invalid \n");
		}
}

//LinearSearch Normal Method Funtion
void LinearSearch(struct array *arr,int key)
{
	int i,x=0;
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i]==key)
		{
			printf("The element is found at location %d\n",i);
			x=1;
			break;
		}
	}
	if(!x)
	{
		printf("The element is not present in the array\n");
	}
}

//LinearSearch Move to previous index Function
void LinearSearchSwapToPrev(struct array *arr,int key)
{
	int i,x=0;
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i]==key)
		{
			swap(&arr->A[i],&arr->A[i-1]);
			printf("The element is found at the location %d\n",i);
			x=1;
			break;
		}
	}
	if(!x)
	{
		printf("The element is not present in the array\n");
	}
}

//LinearSearch Move to Head/First index Function
void LinearSearchSwapToHead(struct array *arr,int key)
{
	int i,x=0;
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i]==key)
		{
			swap(&arr->A[i],&arr->A[0]);
			printf("The element is found at the location %d\n",i);
			x=1;
			break;
		}
	}
	if(!x)
	{
		printf("The element is not present in the array\n");
	}
}

//Binary Search Normal method Function
void BinSearch(struct array *arr,int key)
{
	int low=0;
	int high=arr->length-1;
	int mid,x=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr->A[mid]==key)
		{
			printf("The element is found at index %d",mid);
			x=1;
			break;
		}
		else if(key<arr->A[mid])
		{
			high=mid-1;
		}
		else if(key>arr->A[mid])
		{
			low=mid+1;
		}
	}
	if(x==0)
	{
		printf("The element is not found\n");
	}
}

//Binary Search Recursion method Function
void RevBinSearch(struct array arr,int low,int high,int key)
{
	int mid,x=0;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(arr.A[mid]==key)
		{
			printf("The element is found at location %d\n",mid);
			x=1;
		}
		else if(key<arr.A[mid])
		{
			RevBinSearch(arr,low,mid-1,key);
		}
		else if(key>arr.A[mid])
		{
			RevBinSearch(arr,mid+1,high,key);
		}
	}
	else
	{
		printf("The element is not found\n");
	}
	
}

//Get Function
void Get(struct array arr,int index)
{
	if(index>=0 && index<arr.length)
	{
		printf("The number at given index is %d\n",arr.A[index]);
	}
	else
	{
		printf("The given index is not valid");
	}
}

//Set Function
void Set(struct array *arr,int index,int x)
{
	if(index>=0 && index<arr->length)
	{
		arr->A[index]=x;
	}
	else
	{
		printf("The given index is not valid");
	}
}

//Max Function
void Max(struct array arr)
{
	int i;
	int max=arr.A[0];
	for(i=0;i<arr.length;i++)
	{
		if(max<arr.A[i])
		{
			max=arr.A[i];
		}
	}
	printf("\nThe maximum value in the array is: %d\n",max);
}

//Min Function
void Min(struct array arr)
{
	int i,min=arr.A[0];
	for(i=0;i<arr.length;i++)
	{
		if(arr.A[i]<min)
		{
			min=arr.A[i];
		}
	}
	printf("The minimum value in the array is: %d\n",min);
}

//Sum Function
int Sum(struct array arr)
{
	int sum=0,i;
	for(i=0;i<arr.length;i++)
	{
		sum+=arr.A[i];
	}	
	return sum;
}

//Average Function
float Avg(struct array arr)
{	
	return (float)Sum(arr)/arr.length;
}

//Reverse by copying the content to second array in reverse order and again copy to the initial array
void Rev1(struct array *arr)
{
	int i,j;
	int *B;
	B=(int*)malloc(arr->size*sizeof(int));
	for(i=arr->length-1,j=0;i>=0,j<arr->size;i--,j++)
	{
		B[j]=arr->A[i];
	}
	for(i=0;i<arr->size;i++)
	{
		arr->A[i]=B[i];
	}
}

//Reverse the array bby swapping each equidistant element
void Rev2(struct array *arr)
{
	int i,j;
	for(i=0,j=arr->length-1;i<j;i++,j--)
	{
		swap(&arr->A[i],&arr->A[j]);
	}
}

//Left Shift Function
void lShift(struct array *arr)
{
	int i;
	for(i=0;i<arr->length-1;i++)
	{
		arr->A[i]=arr->A[i+1];
	}
	printf("\nThe elements in the array after left shift are: \n");
	for(i=0;i<arr->length-1;i++)
	{
		printf("%d ",arr->A[i]);
	}
}

//Right Shift Function
void rShift(struct array *arr)
{
	int i;
	for(i=arr->length-1;i>0;i--)
	{
		arr->A[i]=arr->A[i-1];
	}
	printf("\nThe elements in the array after right shift are: \n");
	for(i=1;i<=arr->length-1;i++)
	{
		printf("%d ",arr->A[i]);
	}
}

//Left Rotation Function
void lRot(struct array *arr)
{
	int i,x;
	x=arr->A[0];
	for(i=0;i<arr->length-1;i++)
	{
		arr->A[i]=arr->A[i+1];
	}
	arr->A[arr->length-1]=x;
	printf("\nThe elements in the array after left rotation are: \n");
	for(i=0;i<=arr->length-1;i++)
	{
		printf("%d ",arr->A[i]);
	}
}

//Left Rotation Function
void rRot(struct array *arr)
{
	int i,x;
	x=arr->A[arr->length-1];
	for(i=arr->length-1;i>0;i--)
	{
		arr->A[i]=arr->A[i-1];
	}
	arr->A[0]=x;
	printf("\nThe elements in the array after right rotation are: \n");
	for(i=0;i<=arr->length-1;i++)
	{
		printf("%d ",arr->A[i]);
	}
}

//Insert in sorted array Funtion
void InsertSort(struct array *arr,int x)
{
	int i;
	if(arr->length<arr->size)
	{
		for(i=arr->length-1;x<arr->A[i];i--)
		{
			arr->A[i+1]=arr->A[i];
		}
		arr->A[i+1]=x;
		arr->length++;
	}
	else
	{
		printf("The elements canot be inserted due to no empty spaces\n");
	}
}

//Is sorted or not Function
void IsSort(struct array arr)
{
	int i,x=1;
	for(i=0;i<arr.length-1;i++)
	{
		if(arr.A[i]>arr.A[i+1])
		{
			x=0;
		    break;
		}
	}
	if(x)
	{
		printf("The elements are in sorted order");
	}
	else
	{
		printf("The elements are not in sorted order");
	}
}

//-ve on left side and +ve on right side
void Arrange(struct array *arr)
{
	int i=0,j=arr->length-1;
	while(arr->A[i]<0)
	{
		i++;
	}
	while(arr->A[j]>0)
	{
		j--;
	}
	if(i<j)
	{
		swap(&arr->A[i],&arr->A[j]);
	}
}

struct array* Merge(struct array *arr,struct array *arr2)
{
	int i,j,k;
	i=j=k=0;
	struct array *arr3=(struct array *)malloc(sizeof(struct array));
	while(i<arr->length && j<arr2->length)
	{
		if(arr->A[i]<arr2->A[j])
		{
			arr3->A[k]=arr->A[i];
			i++;k++;
		}
		else 
		{
			arr3->A[k]=arr2->A[j];
			j++;k++;
		}
	}
	for(;i<arr->length;i++)
	{
		arr3->A[k]=arr->A[i];
		k++;
	}
	for(;j<arr2->length;j++)
	{
		arr3->A[k]=arr2->A[j];
		k++;
	}
	arr3->size=arr->size+arr2->size;
	arr3->length=arr->length+arr2->length;
	return arr3;
}





//Main Function
int main()
{
	int i,ch,n,m,x,index;
	struct array arr,arr2,*arr3;
	printf("Enter the size of the array: \n");
	scanf("%d",&arr.size);
	arr.A=(int*)malloc(arr.size*sizeof(int));
	arr.length=0;
	printf("Enter the numner of element you want in the array: \n");
	scanf("%d",&n);
	arr.length=n;
	printf("Enter the elements in the array: \n");
	for(i=0;i<arr.length;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	Display(arr);
	
	do
	{
		//Menu Options
		printf("\n\n************* M E N U *************\n");
		printf("1.  Display\n");
		printf("2.  Append\n");
		printf("3.  Insert\n");
		printf("4.  Delete\n");
		printf("5.  LinearSearch\n");
		printf("6.  LinearSearchSwapToPrev\n");
		printf("7.  LinearSearchSwapToHead\n");
		printf("8.  BinSearch\n");
		printf("9.  RevBinSearch\n");
		printf("10. Get\n");
		printf("11. Set\n");
		printf("12. Max\n");
		printf("13. Min\n");
		printf("14. Sum\n");
		printf("15. Average\n");
		printf("16. Reverese using a new array\n");
		printf("17. Reverse using swapping\n");
		printf("18. Left Shifting\n");
		printf("19. Right Shifting\n");
		printf("20. Left Rotation\n");
		printf("21. Right Rotation\n");
		printf("22. Insert in Sorted Array\n");
		printf("23. IsSorted or not\n");
		printf("24. -ve on left side and +ve on right side\n");
		printf("25. Merge the intial array with the new array, make sure all the array to be sorted\n");


		
		printf("\n\nEnter your choice: \n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				Display(arr);
				break;
			case 2:
				printf("Enter the elements to be appended: \n");
				scanf("%d",&x);
				Append(&arr,x);
				break;
			case 3:
				printf("Enter the index where the number has to be inserted: \n");
				scanf("%d",&index);
				printf("Enter the number to be inserted: \n");
				scanf("%d",&x);
				Insert(&arr,index,x);
				break;
			case 4:
				printf("Enter the index where the number has to be deleted\n");
				scanf("%d",&index);
				Delete(&arr,index);
				break;
			case 5:
				printf("Enter the number to be searched in the array\n");
				scanf("%d",&x);
				LinearSearch(&arr,x);
				break;
            case 6:
            	printf("Enter the number to be searched in the array\n");
            	scanf("%d",&x);
            	LinearSearchSwapToPrev(&arr,x);
            	break;
            case 7:
            	printf("Enter the number to be searched in the array\n");
            	scanf("%d",&x);
            	LinearSearchSwapToHead(&arr,x);
            	break;
            case 8:
            	printf("Enter the number to be searched in the array\n");
            	scanf("%d",&x);
            	BinSearch(&arr,x);
            	break;
            case 9:
            	printf("Enter the number to be searched in the array\n");
            	scanf("%d",&x);
            	RevBinSearch(arr,0,arr.length-1,x);
            	break;
            case 10:
            	printf("Enter the index whose value you want to know\n");
            	scanf("%d",&index);
            	Get(arr,index);
            	break;
            case 11:
            	printf("Enter the index whose value you want to set\n");
            	scanf("%d",&index);
            	printf("Enter the value you want to set to the mentioned index\n");
            	scanf("%d",&x);
            	Set(&arr,index,x);
            	break;
            case 12:
            	Max(arr);
            	break;
            case 13:
            	Min(arr);
            	break;
            case 14:
            	printf("The sum of the elements in the array is: %d\n",Sum(arr));
            	break;
            case 15:
            	printf("The sum of the elements in the array is: %.2f\n",Avg(arr));
            	break;
            case 16:
            	Rev1(&arr);
            	Display(arr);
            	break;
            case 17:
            	Rev2(&arr);
            	Display(arr);
            	break;
            case 18:
            	lShift(&arr);
            	break;
            case 19:
            	rShift(&arr);
            	break;
            case 20:
            	lRot(&arr);
            	break;
            case 21:
            	rRot(&arr);
            	break;
            case 22:
            	printf("Enter the number to be inserted: \n");
				scanf("%d",&x);
            	InsertSort(&arr,x);
            	break;
	        case 23:
	        	IsSort(arr);
	        	break;
	        case 24:
	        	Arrange(&arr);
				break;
			case 25:
				printf("Enter the size of the 2nd array: \n");
	 		    scanf("%d",&arr2.size);
				arr2.A=(int *)malloc(arr2.size*sizeof(int));
				arr2.length=0;
				printf("Enter the number of elements you want to enter: \n");
				scanf("%d",&m);
				arr2.length=m;
				printf("Enter the elements in the array: \n");
				for(i=0;i<arr2.length;i++)
					{
						scanf("%d",&arr2.A[i]);
					}
				arr3=Merge(&arr,&arr2);
				Display(*arr3);
        
		}
	}
		while(ch<26);	
}
