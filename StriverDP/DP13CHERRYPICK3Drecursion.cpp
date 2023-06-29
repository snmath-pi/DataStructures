#include <bits/stdc++.h> 
int dfs(int i, int j1, int j2, int &r, int &m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    if(i == r-1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int mx = -1e8;
    for(int u = -1; u <= 1; u++) {
        for(int v = -1; v <= 1; v++) {
            int vl = 0;
            if(j1 == j2) vl =grid[i][j1];
            else {
                vl = grid[i][j1] + grid[i][j2];
            }
            vl += dfs(i + 1, j1 + u, j2 + v, r, m, grid, dp);
            mx = max(mx, vl);
        }
    }
    return dp[i][j1][j2] = mx;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.

    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int>(c, -1)));

    return dfs(0, 0, c-1,r, c, grid, dp);

}
