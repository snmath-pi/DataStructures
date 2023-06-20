//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        // the formual used is nCr = nCr-1 + n-1Cr-1 pascals identity 
        constexpr int mod = 1e9 + 7;
        // space can be O(R) or O(N * R)
        // O(R) could be used considering the fact we only need curretnt and previous row values
        long long dp[r + 1] = {0};
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j = min(i, r); j >0; j--) {
                dp[j] += dp[j-1]; dp[j] %= mod;
            }
                
        }
        return dp[r];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends
