#include<stdio.h>
struct Array {
	int A[10];
	int length;
	int size;
	
};
void Display (struct Array arr)
{
	int i;
	printf("Enter all the elements ");
	for (i=0;i<arr.length;i++)
	printf("%d ",arr.A[i]);

}
int RBinSearch(int a[],int l,int h,int key)
{

 int mid=0;
 if(l<=h)
 {
 mid=(l+h)/2;
 if(key==a[mid])
 return mid;
 else if(key<a[mid])
 return RBinSearch(a,l,mid-1,key);
 }
 else
 return RBinSearch(a,mid+1,h,key);
return -1;
}

int main ()
{
	
	struct Array arr1={{1,3,5,6,7,8,77,777,888},10,8};
	printf("The element is at index %d\n",RBinSearch(arr1.A,0,arr1.length,5));
	Display(arr1);
	return 0;
}
