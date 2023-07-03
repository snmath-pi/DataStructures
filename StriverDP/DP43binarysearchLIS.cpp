class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        const int inf = 1e9;
        vector<int> d(n + 1, inf);
        d[0] = -inf;
        for(int i=0; i<n; i++) {
            int l = upper_bound(d.begin(), d.end(), nums[i]) - d.begin();
            if(d[l-1] < nums[i] && nums[i] < d[l]) {
                d[l] = nums[i];
            }
        }
        int ans = 1;
        for(int i=1; i<=n; i++) {
            if(d[i] != inf) ans = i;
        }

        return ans;
    }
};
