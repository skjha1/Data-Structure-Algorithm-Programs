#include <bits/stdc++.h>
using namespace std;

vector<int> isSubsetPoss(int arr[], int n, int sum) {
	bool t[n + 1][sum + 1]; // DP - matrix
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = false; 
			if (j == 0)
				t[i][j] = true;
		}
	}
// taking from the 2nd row and 2nd column 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // include or exclude
			else
				t[i][j] = t[i - 1][j]; // exclude
		}
	}

	vector<int> v; // contains all subset sums possible with n elements // creating a vector varible to store all the element of the last row 
	for (int j = 0; j <= sum; j++) // from the range we need to exclude the element which is not there in the existing problem 
		if (t[n][j] == true) // keep true to only those place whose subset sum exist
			v.push_back(j); // store in the vector 

	return v;
}

int MinSubsetSumDiff(int arr[], int n) {
	int range = 0;
	for (int i = 0; i < n; i++)
		range += arr[i]; // taking sum of the array for range 

	vector<int> v = isSubsetPoss(arr, n, range);
	int mn = INT_MAX;
	for (int i = 0; i < v.size(); i++) // iterating through the last row of the matrix 
		mn = min(mn, abs(range - 2 * v[i])); // taking minimum from the last row 

	return mn;
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << MinSubsetSumDiff(arr, n) << endl;
	return 0;
}
