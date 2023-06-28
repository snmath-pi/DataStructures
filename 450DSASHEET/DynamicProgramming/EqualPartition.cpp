//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum  = accumulate(arr, arr + N, 0);
        if(sum % 2) return false;
        int target = sum / 2;
        vector<vector<bool>> dp(N, vector<bool> (target + 1, 0));
        for(int i=0; i<N; i++) dp[i][0] = 1;
        if(arr[0] <= target) dp[0][arr[0]] = 1;
        for(int i=1; i<N; i++) {
            for(int j=1; j <= target; j++) {
                bool first = dp[i-1][j];
                bool second = false;
                if(arr[i] <= j) second = dp[i-1][j-arr[i]];
                dp[i][j] = first | second;
            }
        }
        
        return dp[N-1][target];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
