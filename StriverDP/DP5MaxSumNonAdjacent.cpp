#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &a){
    // Write your code here.
    int n = a.size();
    vector<long long> dp(n, 0);
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
      if (i == 1) {
            dp[i] = max(a[0], a[1]);
            continue;
        }
        dp[i] = max(dp[i-1], a[i] + dp[i-2]);
    }

    return dp[n-1];

}
