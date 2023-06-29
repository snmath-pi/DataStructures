class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int to_check1 = 0, maj1 = -2e9, to_check2 = 0, maj2 = -2e9;
        for(int i=0; i<n; i++) {
            if(nums[i] == maj1) to_check1++;
            else if(nums[i] == maj2) to_check2++;
            else if(to_check1 == 0) maj1 = nums[i], to_check1 = 1;
            else if(to_check2 == 0) maj2 = nums[i], to_check2 = 1;
            else to_check1--, to_check2--;
        }
        vector<int> res;
        int cnt0 = 0, cnt1 = 0;
        for(int i=0; i<n; i++) {
            cnt0 += nums[i] == maj1;
            cnt1 += nums[i] == maj2;
        }
        if(cnt0 > n / 3) res.push_back(maj1);
        if(cnt1 > n / 3) res.push_back(maj2);

        return res;
        
    }
};
