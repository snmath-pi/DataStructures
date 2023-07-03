class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0; i<nums.size(); i++) {
            if(i && nums[i] == nums[i-1]) continue;
            for(int l = i + 1, j = nums.size()-1; l < j; ) {
                if(nums[i] + nums[l] + nums[j] == 0) {
                    temp = {nums[i], nums[l], nums[j]};
                    res.push_back(temp);
                    l++, j--;
                    while(l < j && nums[l] == nums[l-1]) l++;
                    while(l < j && nums[j] == nums[j + 1]) j--;

                } else if(nums[i] + nums[l] + nums[j] < 0) l++;
                else j--;
            }
        }
        return res;
    }
};
