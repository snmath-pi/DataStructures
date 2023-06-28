class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int target = sum / 2;
        set<int> dp, ndp;
        dp.insert(0);
        for(int i=0; i<n; i++) {
            ndp.clear();
            if(dp.find(target) != dp.end()) {
                return true;
            }
            for(auto &x: dp) ndp.insert(x + nums[i]);
            for(auto &x: ndp) dp.insert(x);

        }
        return false;
    }
};
