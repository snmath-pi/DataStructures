class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp, -10000000, sizeof(dp)); // set min dp
        dp[0] = nums[0]; // base case just set it to first element
        for(int i=1; i<n; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]); // two case now 
            // dp[i] = nums[i], we decide to freshly start the new 'subarray sum'
            // dp[i] = dp[i-1] + nums[i], we decide to continue extending current 'subarray sum';
        }
        return *max_element(dp, dp + n); // return the max value in dp
    }
};
