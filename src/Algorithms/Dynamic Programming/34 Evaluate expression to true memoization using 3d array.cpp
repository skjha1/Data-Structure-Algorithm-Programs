#include <bits/stdc++.h>
using namespace std;

const int D = 1001;
int dp[2][D][D]; // i,j and istrue and false is changing 

int Solve(string X, int i, int j, bool isTrue) {
	if (i >= j) {
		if (isTrue)
			dp[1][i][j] = X[i] == 'T';
		else
			dp[0][i][j] = X[i] == 'F';
		return dp[isTrue][i][j];
	}

	if (dp[isTrue][i][j] != -1)
		return dp[isTrue][i][j];

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);

		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}

	}

	dp[isTrue][i][j] = ans;

	return ans;
}

int main() {
	string X; cin >> X;

	memset(dp[0], -1, sizeof(dp[0]));
	memset(dp[1], -1, sizeof(dp[1]));

	cout << Solve(X, 0, X.length() - 1, true) << endl;
	return 0;
}
