class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int) nums.size();
        int cur = n - 1;
        while(cur >= 1 && nums[cur-1] >= nums[cur]) cur--;
        cur--;
        if(cur >= 0) {
            int i = n - 1;
            while(i >= 0 && nums[i] <= nums[cur]) i--;
            swap(nums[cur], nums[i]);
        }

        reverse(nums.begin() + cur + 1, nums.end());
    }
};
