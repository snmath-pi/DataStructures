class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), [&](string &s, string &t) {
            return s.length() < t.length();
        });
        auto comp = [&](string s, string t) {
            int n = s.length(), m = t.length();
            if(n - m != 1) return false;
            int i = 0, j = 0;
            while(i < n) {
                if(s[i] == t[j]) i++, j++;
                else {
                    i++;
                }
            }
            return (i == n && j == m);
        };
        int mx = -1e5;
        for(int i=0; i<n; i++) {
            for(int j=0;j <i; j++) {
                if(comp(words[i], words[j])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
