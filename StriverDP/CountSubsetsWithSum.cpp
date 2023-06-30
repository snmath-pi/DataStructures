const int mod = 1e9 + 7;
int dfs(int id, int k, vector<int> &a, vector<vector<int>> &dp){
    if(k == 0) return 1;
    if(id==0) return a[0] == k;
    if(dp[id][k] != -1) return dp[id][k];
    int nottake = dfs(id-1, k, a, dp) % mod;
    int take = 0;
    if(a[id] <= k) take = dfs(id-1, k-a[id], a, dp) % mod;
    return dp[id][k] = (take + nottake) % mod;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	// vector<vector<int>> dpp(arr.size(), vector<int>(k + 1, -1));
	// return dfs(arr.size()-1, k, arr, dpp);
	const int mod = 1e9 + 7;

	int n = arr.size();
	vector<int> dp(k + 1, 0), ndp(k + 1, 0);
	dp[0] = ndp[0] = 1;
	if(arr[0] <= k) dp[arr[0]] = 1;

	for(int i=1; i<n; i++) {
		// ndp[0] = 1;
		for(int j=0; j<=k; j++) {
			int take = 0;
			if(arr[i] <= j) take = dp[j-arr[i]];
			int not_take = dp[j];
			ndp[j] = (take + not_take) % mod;
		}
		swap(dp, ndp);
	}
	return dp[k] % mod;
}
