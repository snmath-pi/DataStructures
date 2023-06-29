class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int64_t, int> mp; int a, b;
        for(int i=0; i<nums.size(); i++) {
            if(mp.find(target-nums[i])!= mp.end() && mp[target-nums[i]] != i) {
                a = i, b = mp[target-nums[i]];
                break;
            }
            mp[nums[i]] = i;
        }
        return {a, b};
    }
};
