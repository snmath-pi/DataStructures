class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, final = -1e9 + 7;
        // thing is mx stores max 'val' that we can add
        // we have two choices either continue extending the 'subarray' or break this 'subarray' and start with a new 'subarray sum'
        // either way final maximum is stored before deciding this
        for(int i=0; i<n; i++) {
            final = max(final, nums[i] + mx); // final = either we break(final), or we decide to continue (final = nums[i]  + mx)
            mx = max(0, mx + nums[i]); // mx = 0(we decide to break ? why: cause the current subarray sum < 0 and sums < 0 contribute negatively is overall final value)
            // mx = mx + nums[i], means we decided to extend the mx val (i.e sum to be added in the next iteration)
        }
        return final; 
    }
};
