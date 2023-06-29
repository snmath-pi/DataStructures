int dfs(int id, int last, vector<vector<int>> &a, vector<vector<int>> &dp) {
    if(id == 0) {
        int mx = 0;
        for(int i=0; i<3; i++) {
            if(i != last) mx = max(mx, a[0][i]);
        }
        return mx;
    }
    if(dp[id][last] != -1) return dp[id][last];
    int mx = 0;
    for(int i=0; i<3; i++) {
        if(i != last) mx = max(mx, a[id][i] + dfs(id-1, i, a, dp));
    }
    return dp[id][last] = mx;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return dfs(n-1, 3, points, dp);
}
