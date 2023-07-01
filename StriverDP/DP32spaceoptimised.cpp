class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.length();
        vector<double> dp(m + 1), ndp(m + 1);
        dp[0] = ndp[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) ndp[j] = dp[j-1] + dp[j];
                else ndp[j] = dp[j];
            }
            swap(dp, ndp);
        }
        return dp[m];
    }
};
