int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = points[0][0], dp[0][1] = points[0][1], dp[0][2] = points[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + points[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + points[i][1];
        dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + points[i][2];

    }

    return max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}
