#include<stdio.h>
struct Array 
{
	int A[10];
	int size;
	int length;
};
 void Display(struct Array arr)
 {
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }
int BinarySearch(struct Array arr,int key)
{
 int l,mid,h;
 l=0;
 h=arr.length-1;
 while(l<=h)
 {
 mid=(l+h)/2;
 if(key==arr.A[mid])
 return mid;
 else if(key<arr.A[mid])
 h=mid-1;
 else
 l=mid+1;
 }
return -1;
}
int main ()
{
	struct Array arr1= {{1,2,43,55,57,87,98,444,999},10,9};
	printf("The element is present at %d position",BinarySearch(arr1,98));
	Display(arr1);
	return 0;
	
}
