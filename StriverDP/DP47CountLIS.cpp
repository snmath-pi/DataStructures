#include <bits/stdc++.h> 
int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int mx = 0, ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1) dp[i] = 1 + dp[j], cnt[i] = cnt[j];
            else if(arr[j] < arr[i] && dp[i] == dp[j] + 1) cnt[i] += cnt[j];
        }
        mx = max(mx, dp[i]);
    }

    for(int i=0; i<n; i++) {
        if(mx == dp[i]) ans += cnt[i];
    }

    return ans;
}
