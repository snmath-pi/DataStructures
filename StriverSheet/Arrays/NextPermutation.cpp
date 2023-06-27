class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int) nums.size();
        int cur = n - 1;
        // next Permutation is the next greater arrangement of array
        // jaise like for 2 3 5 1 4
        // in this case check bit by bit
        // 2 (is at its best position)
        // 3 (also at it's best)
        // 5 (also at it's best)
        // 1 and 4 here it can be observed that in the next bigger arrangement 4 should occur before 1 
        // hence final answer 2 3 5 4 1
        // a thing to be observed about this process is that as long as it's ascending from the start
        // or ascending from the back it's fine to have no change
        // but as soon as this breaks (here for 5/4 or 4/5) then we have to change
        // an extra fact about this time of permuations that are increasing then decreasing 
        // so just start looking for the unimodal point from the back
        while(cur >= 1 && nums[cur-1] >= nums[cur]) cur--;
        cur--;
        if(cur >= 0) {
            // if such point was found
            // for current element find first element less than that
            int i = n - 1;
            while(i >= 0 && nums[i] <= nums[cur]) i--;
            swap(nums[cur], nums[i]);
            // swap them
            // notice the subarray [i + 1, n - 1] still remains sorted
            // proof: let's say we had elements xcurr < xi > xi + 1 > x i + 2 ... x n - 1
            // now we swap xurr with let's say x m 
            // since xm < xcur && xm was > xm + 1
            // hence it's a fact that xcur > xm + 1
            // now to proove second equality xur < xm-1
            // this is already true from first iteration since we already choose xcur because xcur < xi-1
        }

        reverse(nums.begin() + cur + 1, nums.end()); // just reverse the final pointers to make it ascending
    }
};
