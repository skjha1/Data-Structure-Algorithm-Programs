#include <bits/stdc++.h>
using namespace std;

int getMaxNumberOfWays(int coins[], int n, int sum) {
	int t[n + 1][sum + 1];
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= sum; j++)
			if (coins[i - 1] <= j)
				t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
			else
				t[i][j] = t[i - 1][j];

	return t[n][sum];
}

signed main() {
	int n; cin >> n;
	int coins[n];
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	int sum; cin >> sum;

	cout << getMaxNumberOfWays(coins, n, sum) << endl;
	return 0;
}
