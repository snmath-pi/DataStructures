//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int mn = 1e9, mx = -1e9;
        for(int i=0; i < R; i++) mn = min(mn, matrix[i][0]);
        for(int i=0; i < R; i++) mx = max(mx, matrix[i][C-1]);
        
        int for_median = (R * C + 1) / 2;
        while(mn < mx) {
            int mid = mn + (mx - mn) / 2;
            int cur = 0;
            for(int r = 0; r < R; r++) {
                cur += upper_bound(matrix[r].begin(), matrix[r].end(), mid) - matrix[r].begin();
            }
            if(cur < for_median) mn = mid + 1;
            else mx = mid;
        }
        return mn;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
