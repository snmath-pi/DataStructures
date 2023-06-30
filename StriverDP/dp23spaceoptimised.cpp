#include <bits/stdc++.h> 

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    // Write Your Code Here.
    vector<int> dp(w + 1, 0);
    for(int i=0; i<=w; i++) {
        for(int j=0; j<n; j++) {
            if(wt[j] <= i) {
                dp[i] = max(dp[i], val[j] + dp[i-wt[j]]);
            }
        }
    }
    return dp[w];
}
