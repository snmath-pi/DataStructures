#include <bits/stdc++.h> 

int dfs(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j]; int mini = 1e9;
    for(int k=i; k < j; k++) {
        int steps = arr[i-1] * arr[k] * arr[j] + dfs(i, k, arr, dp) + dfs(k + 1, j, arr, dp);
        if(steps < mini) mini = steps;
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return dfs(1, N-1, arr, dp);
}
