class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i + 1; j < nums.size(); j++) {
                if(j != i + 1 && nums[j] == nums[j-1]) continue;
                for(int l = j + 1, r  = nums.size()-1; l < r; ) {
                    int64_t tot = nums[i] + nums[j];
                    tot += nums[l] + nums[r];
                    if(tot == target) {
                        vector<int> res = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(res);
                        l++, r--;
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(r > l && nums[r] == nums[r + 1]) r--;
                    } else if(tot < target) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};
