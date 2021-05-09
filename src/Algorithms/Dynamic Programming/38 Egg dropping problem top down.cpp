#include <bits/stdc++.h>
using namespace std;

const int D = 101;
int t[D][D];

int Solve(int eggs, int floors) {
	if (t[eggs][floors] != -1)
		return t[eggs][floors];

	if (eggs == 1 || floors == 0 || floors == 1) {
		t[eggs][floors] = floors;
		return floors;
	}

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k));
		mn = min(mn, temp_ans);
	}

	return t[eggs][floors] = mn; // store in table for further reference 
}

signed main() {
	int eggs, floors;
	cin >> eggs >> floors;

	memset(t, -1, sizeof(t));

	cout << Solve(eggs, floors) << endl;
	return 0;
}
