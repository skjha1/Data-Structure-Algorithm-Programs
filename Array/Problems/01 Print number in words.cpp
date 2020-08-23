/* 
Print numbers in words
Given  a number as input, if the number is between 1 and 10 both inclusive then print the number in words otherwise print ""not in range"".
Input: 
First line of input contains an integer T which denotes the number of test cases. Then T test cases follows. First line of each test case contains an integer N.
 
Output:  
For each test case, if the number is between 1 and 10 both inclusive then print the number in words in small cases otherwise print ""not in range"" 
Constraints:
1<=T<=1000
1<=N<=100
5
5
6
12
2
10
five
six
not in range
two
ten
4
9
7 
11
8
nine
seven
not in range
eight

@author   Shivendra K jha */

 
#include<iostream>
using namespace std ;
int main ()
{
	int no,i,a[100];
	cin>>no; // taking input from user 
	for (i=1;i<=no;i++)
	cin>>a[i]; // scanning throuh the element passed by user ;
	for (i=1;i<=no;i++)
	{
		if (a[i]>=1 && a[i]<=10)  // Validating condition 
		{
		if(a[i]==1)
	    cout<<"one\n";
	    else if(a[i]==2)
	      cout<<"two\n";
	    else if(a[i]==3)
	      cout<<"three\n";
	    else if(a[i]==4)
	      cout<<"four\n";
	    else if(a[i]==5)
	      cout<<"five\n";
	    else if(a[i]==6)
	      cout<<"six\n";
	    else if(a[i]==7)
	      cout<<"seven\n";
	    else if(a[i]==8)
	      cout<<"eight\n";
	    else if(a[i]==9)
	      cout<<"nine\n";
	    else if(a[i]==10)
	      cout<<"ten\n";
		}
		else 
		cout<<"not in range\n";
	}
return 0;
}
