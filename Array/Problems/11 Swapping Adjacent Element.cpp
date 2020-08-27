/*Swapping Adjacent Element
Enter even number of elements and swap the adjacent elements of the ID array
4
10 20 30 40
20 10 40 30
6
11 12 13 14 15 16
12 11 14 13 16 15
8
2 8 9 4 8 6 5 8
8 2 4 9 6 8 8 5
*/


#include <iostream>
using namespace std;
int main()
{
  int i,n,temp; 
  cin>>n;
  int a[n];
  for(i=0;i<n;i++){
  cin>>a[i];
  }
  for(i=0;i<n;i++){
    if(i%2!=0) // wherever odd index will encounter swapping will take place 
	{
  	  temp=a[i];
      a[i]=a[i-1];
      a[i-1]=temp;
  }
  }
  for(i=0;i<n-1;i++){
  cout<<a[i]<<" ";
  }
  cout<<a[n-1];
	return 0;
}
