class Solution {
private:
    int dfs(int i, int j, vector<vector<int>> &dp, vector<int> &a) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mx = -1e9;
        for(int k=i; k<=j; k++) {
            mx = max(mx, a[k] * a[i-1] * a[j + 1] + dfs(i, k-1, dp, a) + dfs(k + 1, j, dp, a));
        }
        return dp[i][j] = mx;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, -1));
        return dfs(1, n, dp, nums);
    }
};
