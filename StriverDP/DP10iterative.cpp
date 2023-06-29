#include <bits/stdc++.h>

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 1e9));
    // return dfs(n-1, m-1, grid, dp);
    dp[0][0] = grid[0][0];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i + 1 < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + grid[i + 1][j]);
            if(j + 1 < m) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + grid[i][j + 1]);
        }
    }
    return dp[n-1][m-1];
}
