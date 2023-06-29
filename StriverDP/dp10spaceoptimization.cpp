#include <bits/stdc++.h>

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<int> dp(m, 0);
    dp[0] = grid[0][0];
    for(int i=0; i<n; i++) {
        vector<int> ndp(m, 0);
        for(int j=0; j<m; j++) {
          if (i == 0 && j == 0) {
            ndp[j] = grid[0][0];
            continue;
          }
            int up = grid[i][j], down = grid[i][j];
            if(i > 0) up += dp[j];
            else up += 1e9;
            if(j > 0) down += ndp[j-1];
            else down += 1e9;
            ndp[j] = min(up, down);
        }
        swap(dp, ndp);
    }
    return dp[m-1];
    
}
