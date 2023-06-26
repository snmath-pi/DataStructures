//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[510][2010];
    int recur(int i, int remaining, vector<int> &a, int &k) {
        if(i == a.size()) return 0;
        if(dp[i][remaining] != -1) return dp[i][remaining];
        int ans;
        if(a[i] > remaining) {
            ans = (remaining + 1) * (remaining + 1) + recur(i + 1, k - a[i] - 1, a, k);
        } else {
            int c1 = (remaining + 1) * (remaining + 1) + recur(i + 1, k - a[i] - 1, a, k);
            int c2 = recur(i + 1, remaining - a[i] - 1, a, k);
            ans = min(c1, c2);
        }
        dp[i][remaining] = ans;
        return dp[i][remaining];
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
       memset(dp, -1, sizeof(dp));
       recur(0, k, nums, k);
        
        
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
