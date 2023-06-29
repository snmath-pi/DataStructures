#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.

	vector<int> dp(n, 0);
	for(int i=0; i < n; i++) {
		dp[i] = triangle[n-1][i];
	}
	for(int i=n-2; i>=0; i--) {
		vector<int> ndp(n, 0);
		for(int j=i; j>=0; j--) {
			ndp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		}
		swap(dp, ndp);
	}

	return dp[0];
}
