/*
Raju is giving his JEE Main exam. The exam has Q questions and Raju needs S marks to pass. Giving the correct answer to a question awards the student with 4 marks whereas giving the incorrect answer to a question awards the student with negative 3 (-3) marks. If a student chooses to not answer a question at all, he is awarded 0 marks.

Write a program to calculate the minimum accuracy that Raju will need in order to pass the exam.

Input
Input consists of multiple test cases.
Each test case consists of two integers Q and S

Output
Print the minimum accuracy upto 2 decimal places
Print -1 if it is impossible to pass the exam

Sample Input 0

2
10 40
10 33
Sample Output 0

100.00
90.00
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int q, s;
        cin>>q>>s;
        float x=(s+(3*q))/7.00;
        float p=(x/q)*100;
        if(s<=(4*q))
            printf("%0.2f\n", p);
        else
            cout<<"-1"<<endl;
    }   
    return 0;
}