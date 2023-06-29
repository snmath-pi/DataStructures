class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int to_check = 0, maj = 0;
        for(int i=0; i<n; i++) {
            if(to_check == 0) maj = nums[i];
            if(nums[i] == maj) to_check++;
            else to_check--;
        }
        return maj;

    }
};
