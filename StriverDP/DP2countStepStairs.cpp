#include <bits/stdc++.h>
const int mod = 1e9 + 7; 
int cnt(int x, vector<int> &dp) {
    if(x == 0) return 1;
    if(dp[x]) return dp[x] % mod;
    int x1 = (x >= 1 ? cnt(x-1, dp) : 0);
    int x2 = (x >= 2 ? cnt(x-2, dp) : 0);
    return dp[x] = (x1 % mod + x2 % mod) % mod;
}
int countDistinctWays(int n) {
    //  Write your code here.
    vector<int> dp(n + 1, 0);
    return cnt(n, dp) % mod;
}
