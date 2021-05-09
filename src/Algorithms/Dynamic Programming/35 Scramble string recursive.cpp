#include <bits/stdc++.h>
using namespace std;

bool Solve(string X, string Y) {
	if (X.compare(Y) == 0)
		return true;
	if (X.length() <= 1)
		return false;

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) || // these are two condition for swapping and not swapping the string 
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true; // change the  flag to true and break 
			break;
		}
	}

	return flag;
}

int main() {
	string X, Y; cin >> X >> Y;

	if (X.length() != Y.length())
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
