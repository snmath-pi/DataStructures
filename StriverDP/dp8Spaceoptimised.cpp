#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int> dp(n, 0);
	for(int i=0; i<m; i++) {
		vector<int> ndp(n, 0);
		for(int j=0; j<n; j++) {
			if(i == 0 && j == 0) ndp[j] = 1;
			else {
				if(i > 0) ndp[j] += dp[j];
				if(j > 0) ndp[j] += ndp[j-1];
			}
			
		}
		swap(dp, ndp);
	}
	return dp[n-1];
}
