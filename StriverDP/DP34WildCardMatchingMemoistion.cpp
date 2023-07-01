#include "bits/stdc++.h"
bool dfs(int i, int j, string &p, string &t, vector<vector<int>> &dp) {
   if(i < 0 && j < 0) return true;
   if(i < 0 && j >= 0) return false;
   if(j < 0 && i >= 0) {
      int stars = 0;
      for(int k=0; k<=i; k++) if(p[k] != '*') return false;
      return true;
   }
   if(dp[i][j] != -1) return dp[i][j];
   if(p[i] != '*') {
      if(p[i] == '?' || p[i] == t[j]) return dp[i][j] = dfs(i-1, j-1, p,t,dp);
      return dp[i][j] = false;
   }
   bool first = dfs(i-1, j-1, p, t, dp);
   bool second = dfs(i, j-1, p, t, dp);
   bool third = dfs(i-1, j, p, t, dp);
   return dp[i][j] = first | second | third;
   
}
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   vector<vector<int>> dp(pattern.size(), vector<int>(text.size(), -1));
   return dfs(pattern.size()-1, text.size()-1, pattern, text, dp);
}
