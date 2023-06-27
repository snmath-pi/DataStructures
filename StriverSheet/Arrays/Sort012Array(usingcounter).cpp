class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++) cnt0 += nums[i] == 0, cnt1 += nums[i] == 1, cnt2 += nums[i] == 2;
        for(int i=0; i<n; i++) {
            if(cnt0) nums[i] = 0, cnt0--;
            else if(cnt1) nums[i] = 1, cnt1--;
            else nums[i] = 2, cnt2--;
        }

    }
};
