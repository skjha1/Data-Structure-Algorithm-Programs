/*
Halloween is around and Ted Mosby ( who loves kids ) wants to give away candies. Ted has N bags of candies, each bag has Candies equal to A[i] stored in an array A[N]. There are M kids and each kid wants a specific amount of candy C[i] stored in an array C[M].

For every kid i, you are to print "Happy Halloween!" if C[i] is present in the array A[N]. If C[i] is not present in the array, print "Tricky!".

Hint1 : You can use binary search to find out whether an element is present in the array or not.

INPUT

First line contains the number N(1 <= N <= 10^5), size of array A[N]. Second line contains N space separated integers, denoting the elements of the array A. (1 <= A[i] <= 10^9) Third line contains the number M(1 <= M <= 10^5), size of array C[M]. Fourth line contains M space separated integers, denoting the elements of the array C. (1 <= C[i] <= 10^9)

OUTPUT

Print M lines of output. ith line being "Happy Halloween!" if C[i] is present in A[N] and "Tricky!" otherwise.

Sample Input 0

5
2 4 6 8 10
5
5 4 3 2 1
Sample Output 0

Tricky!
Happy Halloween!
Tricky!
Happy Halloween!
Tricky!
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int m, n;
    cin >> n;
    unordered_map<int, int> candies;
    for(int i=0; i<n; i++) {
        int c;
        cin >> c;
        candies[c] = 1;
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int p;
        cin >> p;
        if(candies[p]) cout << "Happy Halloween!\n";
        else cout << "Tricky!\n";   
    }
    return 0;
}