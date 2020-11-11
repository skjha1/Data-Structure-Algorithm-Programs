/*
Write a program to create a queue of size N specified by the user. Then you will be given an K value. K value represents the no.of elements to be inserted into the queue.After giving K no.of elements you will be given a P value. Then You have to delete the P no.of elements in the queue. After completion of entire process print the element from current starting position to ending position.

Input Format

First line contains N value

Second line contains K value followed by K no.of elements

After that you will be given a P value

Constraints

1<=N<=100

1<=K<=100

1<=element<=1000

0<=P<=N

Output Format

print the element from current starting position to ending position.

Sample Input 0

5
4
1
2
3
4
2
Sample Output 0

3 4
Explanation 0

We have to define the queue of size "5" and we have to insert "3" elements in it.

1 will be inserted into the queue first. Then on top of "1", "2" will be inserted and on top of "2" ,"3" will be inserted. Similarly "4".

After that you have delete 2 elements from queue i.e., 1 and 2 will be deleted.

Now we have to print the elements
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    int n, k, p;
    cin >> n >> k;
    queue<int> q;
    for(int i=0; i<k; i++) {
        int val;
        cin >> val;
        q.push(val);
    }
    cin >> p;
    for(int i=0; i<p; i++) {
        q.pop();
    }
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}