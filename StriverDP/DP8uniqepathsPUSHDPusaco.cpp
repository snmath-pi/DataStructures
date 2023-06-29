#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	int dp[m][n];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(i + 1 < m) dp[i + 1][j] += dp[i][j];
			if(j + 1 < n) dp[i][j + 1] += dp[i][j];
		}
	}
	return dp[m-1][n-1];
}
