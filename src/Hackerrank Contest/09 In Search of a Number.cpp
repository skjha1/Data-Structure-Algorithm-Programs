/*
The number just greater than the given number, with the same set of digits, if none exist, print "-1"

Google : Next greatest permutation

Input Format

The first line contains N, the number

Constraints

1<=N<=10^18

Output Format

The number just greater than the given number, with the same set of digits, if none exist, print "-1"

Sample Input 0

125
Sample Output 0

152
*/

#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

void swap(char *a, char *b) 
{ 
    char temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void findNext(char number[], int n) 
{ 
    int i, j; 
    for (i = n-1; i > 0; i--) 
        if (number[i] > number[i-1]) 
        break; 
    if (i==0) 
    { 
        cout << "-1"; 
        return; 
    } 
    int x = number[i-1], smallest = i; 
    for (j = i+1; j < n; j++) 
        if (number[j] > x && number[j] < number[smallest]) 
            smallest = j; 
    swap(&number[smallest], &number[i-1]); 
    sort(number + i, number + n); 
    cout <<number; 
    return; 
} 

int main() 
{ 
    char digits[10];
    cin>> digits;
    int n = strlen(digits); 
    findNext(digits, n); 
    return 0; 
}