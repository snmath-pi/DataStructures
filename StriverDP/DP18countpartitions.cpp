#include <bits/stdc++.h> 
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int k = 0;
    for(int i=0; i<n; i++) k += arr[i];
    if(k - d < 0) return 0;
    if((k - d) % 2) return 0;
    k = (k - d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1));
    const int mod = 1e9 + 7;
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<=k; j++) {
            int not_take = dp[i-1][j];
            int take = 0;
            if(arr[i] <=j) take = dp[i-1][j-arr[i]];
            dp[i][j] = (take + not_take) % mod;
        }
    }

    return dp[n-1][k] % mod;
}


