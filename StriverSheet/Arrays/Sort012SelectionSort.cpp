class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i < n; i++) {
            int mn = min_element(nums.begin() + i, nums.end()) - nums.begin();
            int cur = nums[mn];
            for(int j=mn; j > i; j--) {
                nums[j] = nums[j-1];
            }
            nums[i] = cur;
        }
    }
};
