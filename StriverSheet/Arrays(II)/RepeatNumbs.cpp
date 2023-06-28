class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = (int) nums.size();
        int l = -1, r = n + 1;
        while(r > l + 1) {
            int m = l + r >> 1;
            int cnt = 0;
            for(int i=0; i<n; i++) {
                cnt += (nums[i] <= m);
            }

            if(cnt <= m) l = m;
            else r = m;
        }
        return r;

    }
};
