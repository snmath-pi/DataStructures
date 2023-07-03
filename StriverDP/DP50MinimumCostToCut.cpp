#include <bits/stdc++.h> 

int dfs(int i, int j, vector<vector<int>> &dp, vector<int> &a) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mn = 1e9;
    for(int k = i; k <= j; k++) {
        int cuts = a[j + 1] - a[i-1] + dfs(i, k-1, dp, a) + dfs(k+1, j, dp, a);
        mn = min(mn, cuts);
    }
    return dp[i][j] = mn;
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(n);
    cuts.push_back(0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 1, vector<int> (c + 1, -1));
    return dfs(1, c, dp, cuts);
}
