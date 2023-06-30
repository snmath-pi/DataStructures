#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int k = 0;
	for(int i= 0; i<n; i++) k += arr[i];
	vector<vector<int>> dp(n, vector<int> (k + 1, 0));
	for(int i=0; i<n; i++) dp[i][0] = 1;
	if(arr[0] <= k) dp[0][arr[0]] = 1;
	for(int i=1; i<n; i++) {
		for(int j=1; j<=k; j++) {
			int take = 0; if(arr[i] <= j) take = dp[i-1][j - arr[i]];
			dp[i][j] = dp[i-1][j] | take;
		}
	}

	int mn = 1e9;
	for(int i=0; i<= k / 2; i++) {
		if(dp[n-1][i]) {
			mn = min(mn, k - 2 * i);
		}
	}

	return mn;
}
