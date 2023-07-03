class Solution {
public:
    
    int minCut(string s) {
        vector<vector<bool>> chk(2010, vector<bool> (2010, 0));
        int n = s.size();
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if(s[i] == s[j]) {
                    if(j - i <= 2) chk[i][j] = 1;
                    else {
                        chk[i][j] = chk[i+1][j-1];
                    }
                }
            }
        }

        vector<int> dp(n + 1, 1e9); dp[n] = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j = i; j < n; j++) {
                if(chk[i][j]) dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }
        return dp[0]-1;
    }
};
