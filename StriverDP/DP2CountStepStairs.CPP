#include <bits/stdc++.h> 
int countDistinctWays(int n) {
    //  Write your code here.
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    const int mod = 1e9 + 7;
    for(int i=0; i<=n; i++) {
        if(i + 2 <= n) dp[i+2] += dp[i], dp[i+2] %= mod;
        if(i + 1 <= n) dp[i+1] += dp[i], dp[i+1] %= mod;
    }

    return  dp[n];
}
