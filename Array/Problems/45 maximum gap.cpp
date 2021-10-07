#include <bits/stdc++.h>
using namespace std;
int maxSortedAdjacentDiff(int* arr, int n)
{
	int maxVal = arr[0], minVal = arr[0];
	for (int i = 1; i < n; i++) {
		maxVal = max(maxVal, arr[i]);
		minVal = min(minVal, arr[i]);
	}
	int maxBucket[n - 1];
	int minBucket[n - 1];
	fill_n(maxBucket, n - 1, INT_MIN);
	fill_n(minBucket, n - 1, INT_MAX);
	float delta = (float)(maxVal - minVal) / (float)(n - 1);
	for (int i = 0; i < n; i++) {
		if (arr[i] == maxVal || arr[i] == minVal)
			continue;
		int index = (float)(floor(arr[i] - minVal) / delta);
		maxBucket[index] = max(maxBucket[index], arr[i]);
		minBucket[index] = min(minBucket[index], arr[i]);
	}
	int prev_val = minVal;
	int max_gap = 0;
	for (int i = 0; i < n - 1; i++) {
		if (minBucket[i] == INT_MAX)
			continue;
		max_gap = max(max_gap, minBucket[i] - prev_val);
		prev_val = maxBucket[i];
	}
	max_gap = max(max_gap, maxVal - prev_val);

	return max_gap;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
	for (int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	cout << maxSortedAdjacentDiff(arr, n) << endl;
	return 0;
}
