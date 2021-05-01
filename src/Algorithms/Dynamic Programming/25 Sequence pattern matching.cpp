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
			if (X[i - 1] == Y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

bool SeqPatternMatching(string X, string Y, int n, int m) {
	return LCS(X, Y, n, m) == min(n, m); // condition to get sequence // if string x is there in y print boolean value according to LCS 
}

signed main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	SeqPatternMatching(X, Y, n, m) ? "YES\n" : "NO\n";
	return 0;
}
