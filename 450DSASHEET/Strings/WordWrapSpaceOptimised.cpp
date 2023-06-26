//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
       int n = nums.size();
       int dp[n], ans[n], curlen, cost;
       dp[n-1] = 0, ans[n-1] = n-1;
       for(int i=n-2; i>=0; i--) {
           dp[i] = 1e9 + 7;
           curlen = -1;
           for(int j=i; j<n; j++) {
               curlen += nums[j] + 1;
               if(curlen > k) break;
               if(j == n-1) cost = 0;
               else cost = (k - curlen) * (k - curlen) + dp[j + 1];
               
               if(cost < dp[i]) {
                   dp[i] = cost;
                   ans[i] = j;
               }
           }
       }
       return dp[0];
        
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
