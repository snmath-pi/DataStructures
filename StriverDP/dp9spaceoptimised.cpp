int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<int> dp(m, 0);
    dp[0] = 1;
    constexpr int mod = 1e9 + 7;
    for(int i=0; i<n; i++) {
        vector<int> ndp(m, 0);
        for(int j=0; j<m; j++) {
            if(i == 0 && j == 0) ndp[j] = 1;
            if(mat[i][j] == -1) ndp[j] = 0;
            else {
                if(i > 0) ndp[j] = (ndp[j] + dp[j]) % mod;
                if(j > 0) ndp[j] = (ndp[j] + ndp[j-1]) % mod;
                ndp[j] %= mod;
            }
        }
        swap(dp, ndp);
    }
    return dp[m-1];
}
