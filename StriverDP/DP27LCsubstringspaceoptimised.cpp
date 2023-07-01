#include <bits/stdc++.h> 
int lcs(string &str1, string &str2){
	//	Write your code here.
	int n = str1.length(), m = str2.length();
	int ans = 0;
	vector<int> dp(m + 1), ndp(m + 1);
	for(int i=1; i<=n; i++){
		for(int j=1;j<=m; j++) {
			if(str1[i-1] == str2[j-1]) {
				ndp[j] = 1 + dp[j-1];
				ans = max(ans, ndp[j]);
			} else ndp[j] = 0;
		}
		swap(dp, ndp);
	}
	return ans;
}
