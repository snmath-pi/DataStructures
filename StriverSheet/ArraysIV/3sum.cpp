class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int l = i + 1, r = nums.size() - 1; l < r; ) {
                int64_t tot = nums[i]; tot += nums[l] + nums[r];
                if(tot == 0) {
                    vector<int> ans = {nums[i], nums[l], nums[r]};
                    sort(ans.begin(), ans.end());
                    res.push_back(ans);
                    l++, r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                    while(r > l && nums[r] == nums[r + 1]) r--; 
                } else if(tot < 0) l++;
                else r--;
            }
        }
        return res;
    }
};
