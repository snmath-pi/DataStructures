int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    const int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0] = (mat[0][0] != -1 ? 1 : 0);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == -1) dp[i][j] = 0;
            else {
                if(i + 1 < n) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
                if(j + 1 < m) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
                
            }
        }
    }
    return dp[n-1][m-1] % mod;
}
