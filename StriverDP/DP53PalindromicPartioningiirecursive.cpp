#include <bits/stdc++.h> 
bool chk[2010][2010];
int dfs(int i, int n, vector<int> &dp, string &s) {
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int min_cost = 1e9;
    for(int k=i; k<n; k++) {
        if(chk[i][k]) {
            min_cost = min(min_cost, 1 + dfs(k + 1, n, dp, s));
        }
    }
    return dp[i] = min_cost;
}
int palindromePartitioning(string str) {
    // Write your code here 
    int n = str.size();
    memset(chk, 0, sizeof(chk));
    for(int i=n-1; i>=0; i--) {
        for(int j=i; j<n; j++) {
            if(str[i] == str[j]) {
                if(j - i <= 2) chk[i][j] = 1;
                else chk[i][j] = chk[i+1][j-1];
            }
        }
    }
    vector<int> dp(n, -1);
    return dfs(0, n, dp, str)-1;
}
