/*Bob was bored that day, so she was sitting on the riverbank .Suddenly she notices a talking, White Rabbit with a pocket watch .It ran fast, and she followed it, down a rabbit hole .She fell into the hole and found a magical wonderland with dark trees, beautiful flowers.She found many ways numbered from 1,2,3,........18.she was confused which is the right way that will lead her to her home. She found a cute bird, standing in one of the tree. Alice asked the bird the way to go back to her home.The bird said a two digit number( say 23 ) and asked her to find the sum of its digits (2+3=5) and that numbered way will lead her to her home.Alice was already confused, so pls help Alice in finding the route to her home....

Input Format:
Input consists of an integer corresponding to the 2-digit number.
Output Format:
Output consists of an integer corresponding to the sum of its digits. Refer sample input and output for formatting specifications.

[All text in bold corresponds to input and the rest corresponds to output]
TEST CASE 1

INPUT
23
OUTPUT
Bob must go in path-5 to find her way to home
TEST CASE 2

INPUT
99
OUTPUT
Bob must go in path-18 to find her way to home
*/

#include <stdio.h>
int main() {
	int no,a,b,c;
  scanf("%d",&no);
    a=no/10;
    b=no%10;
    c=-a-b;
    printf("Bob must go in path%d to find her way to home",c);
	return 0;
}
--------------------------------------------------------------

#include <stdio.h>
 
int main()
{
    int num, temp, digit, sum = 0;
 
    
    scanf("%d", &num);
    temp = num;
    while (num > 0)
    {
        digit = num % 10;
        sum  = sum + digit;
        num /= 10;
    }
    printf("Bob must go in path-%d to find her way to home",sum);
  return 0;
}