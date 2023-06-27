class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, final = -1e9 + 7;
        for(int i=0; i<n; i++) {
            final = max(final, nums[i] + mx);
            mx = max(0, mx + nums[i]);
        }
        return final;
    }
};
