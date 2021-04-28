#include <bits/stdc++.h>
using namespace std;

int CountSubsetsWithSum(int arr[], int n, int sum) {
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization 
  // here we are setting 1st row and 1st column 
  // i denotes the size of the array 
  // j denotes the target sum (subset sum)
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0) // when array(i) is empty than there is no meaning of sum of elements so return count of subset as 0;
				t[i][j] = 0;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return count as 1;
				t[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) // when element in the list is less then target sum 
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; // either exclude or inxlude and add both of them to get final count 
			else
				t[i][j] = t[i - 1][j]; // exclude when element in the list is greater then the sum 
		}
	}

	return t[n][sum]; // finally return the last row and last column element 
}

int CountSubsetsWithDiff(int arr[], int n, int diff) {
	int sumOfArray = 0;
	for (int i = 0; i < n; i++)
		sumOfArray += arr[i]; // taking sum of the array 

	if ((sumOfArray + diff) % 2 != 0)
		return 0;
	else
		return CountSubsetsWithSum(arr, n, (sumOfArray + diff) / 2);// we will get the number of array(subset) with particular sum 
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int diff; cin >> diff;

	cout << CountSubsetsWithDiff(arr, n, diff) << endl;
	return 0;
}
