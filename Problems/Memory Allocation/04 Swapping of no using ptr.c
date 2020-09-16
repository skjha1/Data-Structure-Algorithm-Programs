/*Rahul and Ram played a game of exchanging their pocket money on a holiday. Rahul tries to give his pocket money to Ram and get Ram's pocket money.
Both of them were strucking in to solve the problem. You help them to solve the problem
TEST CASE 1

INPUT
5 4
OUTPUT
x=5
y=4
After Swapping
x=4
y=5
TEST CASE 2

INPUT
100 239
OUTPUT
x=100
y=239
After Swapping
x=239
y=100
*/
#include<iostream>
using namespace std;
int main ()
{
  int *a,*b,temp,x,y;
  scanf("%d%d",&x,&y);
  printf("x=%d\ny=%d\n",x,y);
  
  a=&x;// a assign to x 
  b=&y;// b assign to y
  
  temp=*a;
  *a=*b;
  *b=temp;
  printf("After Swapping\n");
  printf("x=%d\ny=%d\n",x,y);
  return 0;
}
  