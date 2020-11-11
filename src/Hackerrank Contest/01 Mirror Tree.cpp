/* 
When a tree is reflected across an imaginary straight vertical line right or left of the entire tree, the resultant tree hence obtained is the mirror tree of the original tree.

Your task is to write a program to check if two given trees are mirrors of each other.

Input
First line consists of the number of nodes N.
Next N-1 lines each describes the first tree. Each line has two integers U and V and a letter 'R' or 'L', denoting that V is the left or the right child of U.
Next N-1 lines each describes the second tree. Each line has two integers U and V and a letter 'R' or 'L', denoting that V is the left or the right child of U.

Output
Print "yes" if the two trees are mirrors of each other and "no" otherwise

Sample Input 0

3
1 2 R
1 3 L
1 2 L
1 3 R
Sample Output 0

yes
Explanation 0

The first tree is

  1 

 / \ 

3   2
The second tree is

  1 

 / \ 

2   3
Clearly, both the trees are mirrors of each other.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<int, vector<pair<int, char>>> rec;
    for(int i=0; i<n-1; i++) {
        int root, leaf;
        char side;
        cin >> root >> leaf >> side;
        rec[root].push_back(make_pair(leaf, side));
    }
    bool trigger = true;
    for(int i=0; i<n-1; i++) {
        int root, leaf;
        char side;
        cin >> root >> leaf >> side;
        bool flag = false;
        for(auto x: rec[root]) {
            if(x.first == leaf && x.second != side) flag = true;
        }
        if(!flag) {
            trigger = false;
            break;
        }
    }
    if(trigger) cout << "yes";
    else cout << "no";
    return 0;
}