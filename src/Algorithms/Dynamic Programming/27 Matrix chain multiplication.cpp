#include <bits/stdc++.h>
using namespace std;

int Solve(int arr[], int i, int j) {
	if (i >= j)
		return 0;

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans); // take temp minimum value from the temp answers
	}

	return ans;
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << Solve(arr, 1, n - 1) << endl;
	return 0;
}
