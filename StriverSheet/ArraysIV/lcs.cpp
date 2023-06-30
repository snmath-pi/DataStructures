class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> s;
        for(auto &x: nums) s.insert(x); int res = 1;
        for(auto &x: s) {
            if(s.count(x-1) == 0) {
                int search = x, cnt = 1;
                while(s.count(search+1)) search++, cnt++;
                res = max(res, cnt); 
            }
        }
        return res;
    }
};
