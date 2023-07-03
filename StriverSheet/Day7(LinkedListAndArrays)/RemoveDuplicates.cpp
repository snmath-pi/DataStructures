class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for(int i=0; i<nums.size(); i++) {
            int cur = nums[i], j = i;
            while(i< nums.size() && nums[i] == cur) i++;
            if(i!=j) i--;
            nums[idx++] = cur;
        }
        return idx;

    }
};
