/*
Given an array of size N containing 0s, 1s, and 2s; sort the array in ascending order.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which will contain N. The second lines contains the elements of the array.

Output: 
Print sorted array.

Your Task:
Complete the function sort012() that takes array and n and sorts the array in place. 

Constraints: 
1 <= T <= 50
1 <= N <= 10^5
0 <= A[i] <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
*/

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int no,i,num;

		cin >> no;
		int count0 = 0;
		int count1 = 0;
		int count2 = 0;
		for (i = 0; i < no; i++)
		{
			cin >> num;
			if (num == 0)
				count0++;
			if (num == 1)
				count1++;
			if (num == 2)
				count2++;

		}
		while (count0--) {
			cout << "0 ";
		}
		while (count1--) {
			cout << "1 ";
		}
		while (count2--) {
			cout << "2 ";
		}
		cout << endl;
	}
	return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int no;
		cin >> no;
		int A[10];
		for (int i = 0; i < no; i++) {
			cin >> A[i];
		}
		sort(A, A + no);
		for (int i = 0; i < no; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	return 0;
}