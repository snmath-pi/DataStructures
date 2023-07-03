#include <bits/stdc++.h> 
const int mod = 1e9 + 7;
int64_t dfs(int i, int j, int flag, vector<vector<vector<int64_t>>> &dp, string &s) {
    if(i > j) return 0;
    if(i == j) {
        if(flag) return s[i] == 'T';
        else return s[i] == 'F';
    }
    if(dp[i][j][flag] != -1) return dp[i][j][flag] % mod;

    int64_t cnt = 0;
    for(int k = i + 1; k <= j-1; k += 2) {
        int64_t lt = dfs(i, k-1, 1, dp, s) % mod;
        int64_t lf = dfs(i, k-1, 0, dp, s) % mod;
        int64_t rt = dfs(k + 1, j, 1, dp, s) % mod;
        int64_t rf = dfs(k + 1, j, 0, dp, s) % mod;
        if(s[k] == '&') {
            if(flag) {
                cnt = (cnt % mod + (lt % mod * rt % mod) % mod) % mod;
                cnt %= mod;
            } else {
                cnt = (cnt % mod + (lt % mod * rf % mod) % mod) % mod;
                cnt = (cnt % mod + (lf % mod * rt % mod) % mod) % mod;
                cnt = (cnt % mod + (lf % mod * rf % mod) % mod) % mod;
                cnt %= mod;

            }
        } else if(s[k] == '|') {
            if(flag) {
                cnt = (cnt % mod + (lt % mod * rt % mod) % mod) % mod;
                cnt = (cnt % mod + (lt % mod * rf % mod) % mod) % mod;
                cnt = (cnt % mod + (lf % mod * rt % mod) % mod) % mod;
                cnt %= mod;
            } else {
                cnt = (cnt % mod + (lf % mod * rf % mod) % mod) % mod;
                cnt %= mod;
            }
        } else {
            if(flag) {
                cnt = (cnt % mod + (lt % mod * rf % mod) % mod) % mod;
                cnt = (cnt % mod + (lf % mod * rt % mod) % mod) % mod;
                cnt %= mod;
            } else {
                cnt = (cnt % mod + (lt % mod * rt % mod) % mod) % mod;
                cnt = (cnt % mod + (lf % mod * rf % mod) % mod) % mod;
                cnt %= mod;
            }
        }
    }
    return dp[i][j][flag] = cnt % mod;
}
int evaluateExp(string & exp) {
    // Write your code here.
    vector<vector<vector<int64_t>>> dp(exp.size(), vector<vector<int64_t>> (exp.size(), vector<int64_t>(2, -1)));
    return dfs(0, exp.size()-1, 1, dp, exp) % mod;

}
