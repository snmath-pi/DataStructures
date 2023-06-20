//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       // nlogn can be used by changing state of dp
       // for N2 solution we used dp[i] -> max length till ith index
       // for nlogn used dp[l] -> smallest number ending at ith index which is the end of some subsequence
       constexpr int inf = 1e9;
       vector<int> dp(n + 1, inf);
       dp[0] = -inf;
       for(int i=0; i<n; i++) {
           int x = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
           if(dp[x-1] < a[i] && a[i] < dp[x]) {
               dp[x] = a[i];
           }
       }
       int mx = 0;
       for(int i=1; i<=n; i++) {
           if(dp[i] < inf) {
               mx = i;
           }
       }
       return mx;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
