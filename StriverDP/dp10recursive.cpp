#include <bits/stdc++.h>
int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(i < 0 || j < 0) return 1e9;
    if(i == 0 && j == 0) return grid[0][0];
    if(dp[i][j] != 1e9) return dp[i][j];
    return dp[i][j] = min(dfs(i-1, j, grid, dp), dfs(i, j-1, grid, dp)) + grid[i][j];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 1e9));
    return dfs(n-1, m-1, grid, dp);
    
}
