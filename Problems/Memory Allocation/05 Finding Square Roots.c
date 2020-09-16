/*
In olden days finding square roots seemed to be difficult but nowadays it can be easily done using in-built functions available across many languages .

Assume that you happen to hear the above words and you want to give a try in finding the square root of any given integer using in-built functions. So here's your chance.
Input

The first line of the input contains an integer T, the number of test cases. T lines follow. Each T contains an integer N whose square root needs to be computed.
Output

For each line of input output the square root of the input integer.
Constraints

1<=T<=20
1<=N<=10000
TEST CASE 1

INPUT
3
10
5
10000
OUTPUT
3
2
100
TEST CASE 2

INPUT
1
10
OUTPUT
3
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int no,*p,i,a;
  scanf("%d",&no);
  p=(int *)malloc(no*sizeof(int));
  for (i=0;i<no;i++){
    
    scanf("%d",p+i);
  }
  for(i=0;i<no;i++){
    a=sqrt(*p);
    p++;
     printf("%d\n",a);
  }note 
	return 0;
}