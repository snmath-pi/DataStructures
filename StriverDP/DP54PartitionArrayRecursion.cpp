class Solution {
public:
    int dfs(int i, int &n, vector<int> &dp, vector<int> &a, int &k) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int len = 0, mxe = -1e9, res = -1e9;
        for(int j= i; j < min(i + k, n); j++) {
            len++;
            mxe = max(mxe, a[j]);
            res=  max(res, len * mxe + dfs(j + 1, n, dp, a, k));
        }
        return dp[i] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return dfs(0, n, dp, arr, k);
    }
};
