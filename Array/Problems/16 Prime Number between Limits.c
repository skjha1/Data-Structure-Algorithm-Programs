/* 

Prime Number between Limits
QUESTION DESCRIPTION

"As we all know, Virat Kohli is in the form of his life and hitting centuries has become his habit. Bollywood diva Anushka Sharma is interested in knowing if the number of centuries he would score in two consecutive years would be two consecutive prime numbers (e.g. 7 and 11 ) and successor of sum of both those numbers would also be a prime number p. She gave him numbers n and k and asks if there lie at least k possible values of p between 2 and n. Virat is not a great mathematician and fails to tell her and they broke up on news of which Rohit Sharma is the happiest man on earth. Now, Rohit wants to impress Anushka by giving the answer and doesnt want to take a chance. So, Rohit hires you to write a program for himself that calculates the answer of the question posed by Anushka.
Input
The only line of input contains two numbers n and k.
Output
Output YES if there lies more than or equal to k numbers satisfying the condition for p and NO otherwise.
TEST CASE 1

INPUT
10 1
OUTPUT
NO
TEST CASE 2

INPUT
25 2
OUTPUT
YES

*/

#include <stdio.h>
int main()
{
	int n,k,flag=0,l=0; // takin n and k as input 
  int i,j,count=0,number[50];
  scanf("%d %d",&n,&k);
  for(i=2;i<=n;i++)  // scanning through elements in btw 
  {
   for(j=2;j<=i/2;j++)
   {
    if(i%j==0)
    {
     flag=1; // if flag become 1 we will come out
      break;
    }
   }
    if(flag==0)
    {
      number[l]=i; // taking prime no to be added
      l++;
    }
    flag=0; // again set flag as zero and rotate in loop 
  }
  for(i=0;i<l;i++)
  {int k,flag=0;
   k=number[i]+number[i+1]+1; // applying logic i.e successor of sum of both those numbers would also be a prime number
    for(j=2;j<=k/2;j++)
    {
      if(k%j==0)
      {
       flag=1;
        break;
      }
    }
   if(flag==0)
   {
     count++;
   }
  }
  if(count>k)
  {
   printf("YES") ;
  }
  else
  {
   printf("NO"); 
  }
	return 0;
}
