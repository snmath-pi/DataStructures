class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int cur = -1e9, len = 1, res = 1;
        for(auto &x: nums) {
            if(x == cur + 1) {
                len++;
                cur = x;
            } else if(x == cur) {
                continue;
            } else {
                cur = x;
                len = 1;
            }
            res = max(res, len);
        }
        return res;
    }
};
