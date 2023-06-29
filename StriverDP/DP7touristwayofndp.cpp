int ninjaTraining(int n, vector<vector<int>> &a)
{
    // Write your code here.
    vector<int> dp(3, 0);
    dp[0] = a[0][0], dp[1] = a[0][1], dp[2] = a[0][2];
    for(int i=1; i<n; i++) {
        vector<int> ndp(3, 0);
        ndp[0] = max(dp[1], dp[2]) + a[i][0];
        ndp[1] = max(dp[0], dp[2]) + a[i][1];
        ndp[2] = max(dp[1], dp[0]) + a[i][2];
        swap(dp, ndp);
    }
    return max(max(dp[0], dp[1]), dp[2]);
}
