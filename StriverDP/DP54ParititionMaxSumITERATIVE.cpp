class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1e9);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--) {
            int len = 0, mx = -1e9;
            for(int j = i; j < min(i + k, n); j++) {
                len++; mx = max(mx, arr[j]);
                dp[i] = max(dp[i], mx * len + dp[j + 1]);
            }
        }
        return dp[0];
    }
};
