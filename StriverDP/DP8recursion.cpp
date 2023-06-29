#include <bits/stdc++.h> 
int dfs(int i, int j, vector<vector<int>> &dp) {
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = dfs(i-1, j, dp) + dfs(i, j-1, dp);
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return dfs(m-1, n-1, dp);
}
