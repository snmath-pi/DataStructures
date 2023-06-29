class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int res = 0;
        for(int i=0, j = 0; i < s.size(); i++) {
            if(mp[s[i]]) {
                j = max(j, mp[s[i]]);
            }
            res = max(res, i - j + 1);
            mp[s[i]] = i + 1;
        }
        return res;
    }
};
