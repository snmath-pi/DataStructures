#include "bits/stdc++.h"

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n = pattern.length(), m = text.length();
   vector<bool> dp(m + 1, false), ndp(m + 1, false);
   dp[0] = true;
   
   for(int i=1; i<=n; i++) {
      bool ok = true;
      for(int j = 1; j <= i; j++) {
         if(pattern[j-1] != '*') {
            ok = false; break;
         }
      }
      ndp[0] = ok;
      for(int j=1; j<=m; j++) { 
         if(pattern[i-1] == '?' || pattern[i-1] == text[j-1]) ndp[j] = dp[j-1];
         else if(pattern[i-1] == '*') ndp[j] = ndp[j-1] | dp[j];
         else ndp[j] = false;
      
      }
      swap(dp, ndp);
   }
   return dp[m];
}
