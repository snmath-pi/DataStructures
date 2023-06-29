#include <bits/stdc++.h> 
int dfs(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if(j < 0 || j >= m) return -1e8;
    if(i == 0) return matrix[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max({dfs(i - 1, j - 1, n, m, matrix, dp),
                           dfs(i - 1, j + 1, n, m, matrix, dp),
                           dfs(i - 1, j, n, m, matrix, dp)}) +
                      matrix[i][j];
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size(), mx = -1e8;
    /*
    ~recursion
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for(int i=0; i<m; i++) {
        mx = max(mx, dfs(n-1, i, n, m, matrix, dp));
    }
    return mx;
    */
    /*
    ~tabulation
    vector<vector<int>> dp(n, vector<int> (m, -1e9));
    for(int i=0; i<m; i++) dp[0][i] = matrix[0][i];
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + matrix[i][j]);
            if(j < m - 1) dp[i][j] = max(dp[i][j], dp[i-1][j + 1] + matrix[i][j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j] + matrix[i][j]);
        }
    }
    return *max_element(dp[n-1].begin(), dp[n-1].end()); */
    //  Space Optimised ~
    vector<int> dp(m), ndp(m,0);

    for(int i=0; i < m; i++) dp[i] = matrix[0][i];
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            ndp[j] = -1e8;
            if(j > 0) ndp[j] = max(ndp[j], dp[j-1] + matrix[i][j]);
            if(j < m - 1) ndp[j] = max(ndp[j], dp[j + 1] + matrix[i][j]);
            ndp[j] = max(ndp[j], dp[j] + matrix[i][j]);
        }
        swap(dp, ndp);
    }

    return *max_element(dp.begin(), dp.end()); 
}
