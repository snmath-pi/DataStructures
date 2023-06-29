#include <bits/stdc++.h> 

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<int>> dp(m, vector<int> (m));
    vector<vector<int>> ndp(m, vector<int> (m));

    for(int j1 = 0; j1 < m; j1++) {
        for(int j2 = 0; j2 < m; j2++) {
            if(j1 == j2) {
                dp[j1][j2] = grid[n-1][j1]; 
            } else dp[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
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
                            vl += dp[j1 + u][j2 + v];
                        else vl += -1e8;
                        mx = max(mx, vl);
                    }
                }
                ndp[j1][j2] = mx;
            }
            
        }
        swap(dp, ndp);
    }
    return dp[0][m-1];

}
