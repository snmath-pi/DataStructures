#include <bits/stdc++.h> 
int dfs(int id, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
    if(id == 0) {
        return (w / wt[0]) * val[0];
    }
    
    if(dp[id][w] != -1) return dp[id][w];
    int take = 0;
    if(wt[id] <= w) take = dfs(id, w-wt[id], val, wt, dp) + val[id];
    return dp[id][w] = max(dfs(id-1, w, val, wt, dp), take);
}
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return dfs(n-1, w, val, wt, dp);
}
