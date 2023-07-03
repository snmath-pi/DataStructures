class Solution {
private:
    int dfs(int i, int prev, vector<vector<int>> &dp, vector<int> &nums, int &n) {
        if(i >= n) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int len = dfs(i + 1, prev, dp, nums, n);
        if(prev == -1 || nums[i] > nums[prev]) len = max(len, 1 + dfs(i + 1, i, dp, nums, n));

        return dp[i][prev + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i=n-1; i>=0; i--) {
            for(int prev = i-1; prev>=-1; prev--) {
                dp[i][prev + 1] = dp[i+1][prev+1];
                if(prev == -1 || nums[i] > nums[prev]) 
                    dp[i][prev + 1] = max(dp[i][prev + 1], 1 + dp[i+1][i + 1]);
            }
        }

        return dp[0][0];
    }
};
