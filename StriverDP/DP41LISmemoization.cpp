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
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(0, -1, dp, nums,n);
    }
};
