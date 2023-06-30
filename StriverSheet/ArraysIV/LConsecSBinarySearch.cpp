class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int l = 0, r = n + 1;
        set<int> s;
        for(auto &x: nums) s.insert(x);
        vector<int> a(s.begin(), s.end());
        n = a.size();
        sort(a.begin(), a.end());
        auto good = [&](int m) {
            int res = 0;
            for(int i=0; i<n; i++) {
                if(i + 1 < n) {
                    if(a[i] + 1 == a[i+1]) {
                        int s = i;
                        while(i + 1 < n && a[i] + 1 == a[i + 1]) i++;
                        i--;
                        res = max(res, i - s + 1);
                    }
                }
            }

            return res >= m;
        };
        while(r > l + 1) {
            int m = (l + r) / 2;
            if(good(m)) l = m;
            else r = m;
        }
        return r;
    }
};
