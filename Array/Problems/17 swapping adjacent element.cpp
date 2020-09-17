/*
Enter even number of elements and swap the adjacent elements of the ID array
TEST CASE 1

INPUT
4
10 20 30 40
OUTPUT
20 10 40 30
TEST CASE 2

INPUT
6
11 12 13 14 15 16
OUTPUT
12 11 14 13 16 15
*/
#include<iostream>
using namespace std;
int main ()
{
  int no,i,temp;
  cin>>no;
  int a[no];
  for (i=0;i<no;i++)
    cin>>a[i];
  for(i=0;i<no;i+=2)
  {
    temp=a[i];
    a[i]=a[i+1];
    a[i+1]=temp;
  }
  for (i=0;i<no;i++)
  {
    cout<<a[i]<<" ";
  }
  return 0;
}
    