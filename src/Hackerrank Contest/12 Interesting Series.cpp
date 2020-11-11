/*

Mickey came across an interesting series as follows : FN = FN-1 xor FN-2 + FN-3

He is a better at managing the clubhouse than progamming, so he asked for your help.
He has given you four values, F0, F1, F2 and N. Your task is to write a program to tell him the value of FN.

Input
Four integers separated by spaces denoting F0, F1, F2 and N.

Output
Print one integer equal to the value of FN

Notes
1 ≤ N ≤ 15

Sample Input 0

1 2 3 5
Sample Output 0

6

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int F(int n,int F0,int F1,int F2)
{
    if(n==0)
        return F0;
    else if(n==1)
        return F1;
    else if(n==2)
        return F2;
    else
        return F(n-1,F0,F1,F2)^F(n-2,F0,F1,F2)+F(n-3,F0,F1,F2);
}

int main() {
    int f0,f1,f2,n;
    cin>>f0>>f1>>f2>>n;
    cout<<F(n,f0,f1,f2);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}