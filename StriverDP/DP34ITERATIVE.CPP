#include "bits/stdc++.h"

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n = pattern.length(), m = text.length();
   vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
   dp[0][0] = 1;
   for(int i=1; i<=m; i++) {
      dp[0][i] = false;
   }
   for(int i=1; i<=n; i++) {
      bool ok = true;
      for(int j = 1; j <= i; j++) {
         if(pattern[j-1] != '*') {
            ok = false; break;
         }
      }
      dp[i][0] = ok;
   }
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) { 
         if(pattern[i-1] == '?' || pattern[i-1] == text[j-1]) dp[i][j] = dp[i-1][j-1];
         else if(pattern[i-1] == '*') dp[i][j] = dp[i][j-1] | dp[i-1][j];
      
      }
   }
   return dp[n][m];
}
