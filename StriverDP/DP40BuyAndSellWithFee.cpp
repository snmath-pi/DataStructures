class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(2, 0), ndp(2, 0);
        for(int i=n-1; i>=0; i--) {
            ndp[1] = max(-prices[i] + dp[0], dp[1]);
            ndp[0] = max(prices[i] + dp[1] - fee, dp[0]);
            swap(dp, ndp);
        }

        return dp[1];
    }
};
