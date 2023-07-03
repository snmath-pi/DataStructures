class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subseq;
        int n = nums.size();
        vector<int> dp(n, 1), p(n, -1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    p[i] = j;
                }
            }
        }
        int ans = dp[0], pos=0;
        for(int i=1; i<n; i++) {
            if(dp[i] > ans) {
                pos = i;
                ans = dp[i];
            }
        }
        while(pos != -1) {
            subseq.push_back(nums[pos]);
            pos = p[pos];
        }
        reverse(subseq.begin(), subseq.end());
        return subseq;
    }
};
