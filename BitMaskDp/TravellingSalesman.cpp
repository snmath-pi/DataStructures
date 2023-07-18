#include <bits/stdc++.h> 
long long dfs(int i, int mask, int &n, vector<vector<long long>> &dp, vector<vector<int>> &dis) {
	if(mask == (1 << n)-1) {
		return dis[i][0];
	}
	if(dp[i][mask] != -1) return dp[i][mask];
	long long res = 1e9;
	for(int j=0; j<n; j++) {
		if(((mask >> j) & 1) == 0) {
			res = min(res, dis[i][j] + dfs(j, mask | (1<<j), n, dp, dis));
		}
	}
	return dp[i][mask] = res;
}
int shortestRoute(vector<vector<int>> &distance)
{
	// Write your code here.
	int n =distance.size();
	vector<vector<long long>> dp(n, vector<long long>(1<<n, -1));
	return dfs(0, 1, n, dp, distance);
	
}
