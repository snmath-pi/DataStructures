#include <bits/stdc++.h> 

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m, 0)));
    for(int j1 = 0; j1 < m; j1++) {
        for(int j2 = 0; j2 < m; j2++) {
            if(j1 == j2) {
                dp[n-1][j1][j2] = grid[n-1][j1]; 
            } else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2; i>=0; i--) {
        for(int j1=0; j1 <m; j1++) {
            for(int j2= 0;j2 < m; j2++) {
                int mx = -1e8;
                
                for(int u=-1; u<=1; u++) {
                    for(int v=-1; v<=1; v++) {
                        int vl = 0;
                        if(j1 == j2) vl = grid[i][j2];
                        else vl = grid[i][j1] + grid[i][j2];
                        if(j1 + u >= 0 && j1 + u < m && j2 + v >= 0 && j2 + v < m) 
                            vl += dp[i + 1][j1 + u][j2 + v];
                        else vl += -1e8;
                        mx = max(mx, vl);
                    }
                }
                dp[i][j1][j2] = mx;
            }
        }
    }
    return dp[0][0][m-1];

}
