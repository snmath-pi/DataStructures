#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	   
	  vector<int> dp(n, 1), ndp(n, 1);
	  for(int i=0; i<n; i++) {
		  for(int j=0; j<i; j++) {
			  if(arr[j] < arr[i] && dp[i] < 1 + dp[j]) dp[i] = 1 + dp[j];
		  }
	  }
	  for(int i=n-1; i>=0; --i) {
		  for(int j=n-1; j>i; j--) {
			  if(arr[j] < arr[i] && ndp[i] < 1 + ndp[j]) ndp[i] = 1 + ndp[j];
		  }
	  }

	  int mx = 1;
	  for(int i=0; i<n; i++) mx = max(mx, dp[i] + ndp[i] - 1);

	  return mx;
} 
