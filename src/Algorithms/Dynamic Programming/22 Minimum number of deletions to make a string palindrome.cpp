#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

int LPS(string X, int n) {
	string rev_X = X;
	reverse(rev_X.begin(), rev_X.end());
	return LCS(X, rev_X, n, n);
}
// . minimum number of deletions 
  // min = n – len
int MinDelForPallindrome(string X, int n) {
	return n - LPS(X, n); // substract LPS from the length of string to get Minimum number of deletions to make a string palindrome
}

signed main() {
	string X, Y; cin >> X;
	int n = X.length();

	cout << MinDelForPallindrome(X, n) << endl;
	return 0;
}
