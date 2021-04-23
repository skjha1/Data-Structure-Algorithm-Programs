#include <iostream>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n) {
	int t[n + 1][W + 1]; // DP matrix

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) // base case // filling 1st row and 1st column of the matrix with zero as per the base condition of the recursive solution 
				t[i][j] = 0;
			else if (wt[i - 1] <= j) { // current wt can fit in bag // this is for the choice diagram of the recursive solution
				int val1 = val[i - 1] + t[i - 1][j - wt[i - 1]]; // take current wt // and after taking weight substract the inserted weight from the final weight 
				int val2 = t[i - 1][j]; // skip current wt
				t[i][j] = max(val1, val2);
			}
			else if (wt[i - 1] > j) // current wt doesn't fit in bag
				t[i][j] = t[i - 1][j]; // move to next
		}
	}

	return t[n][W];
}

int main() {
	int n; cin >> n; // number of items
	int val[n], wt[n]; // values and wts array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int W; cin >> W; // capacity

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}

/* Complexity Analysis: 

Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
