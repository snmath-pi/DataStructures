#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for(int i=0; i<n; i++) {
        if(i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(heights[i + 1] - heights[i]));
        if(i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(heights[i+2] -heights[i]));
    }

    return dp[n-1];
}
