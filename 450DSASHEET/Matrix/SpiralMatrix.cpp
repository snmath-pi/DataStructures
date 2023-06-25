//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    #define pb push_back
    #define vvb vector<vb>
    #define rep(i,n) for(int i=0;i<n;++i)
    #define per(i,n) for(int i=n-1;i>=0;--i)
    #define repn(i,n) for(int i=1;i<=n;++i)
    #define rng(i, a, b) for(int i=a; i<b; i++)
    #define gnr(i,a,b) for(int i=b-1;i>=a;--i)
    #define vb vector<bool>
    #define vi vector<int>
    #define vl vector<ll>
    #define vvb vector<vb>
    #define vvi vector<vi>
    #define vvl vector<vl>
    #define si unordered_set<int>
    #define sl unordered_set<ll>
    #define tsi set<int>
    #define tsl set<ll>
    #define pii pair<int, int>
    #define pll pair<ll, ll>
    #define vpii vector<pii>
    #define vpll vector<pll>
    #define tmii map<int, int>
    #define tmll map<ll, ll>
    #define mii unordered_map<int, int>
    #define mll unordered_map<ll, ll>
    #define pqi priority_queue<int>
    #define pqig priority_queue<int, vi, greater<int>>
    #define pql priority_queue<ll>
    #define pqlg priority_queue<ll, vl, greater<ll>>
    #define pqpii priority_queue<pii>
    #define pqpll priority_queue<pll>
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define sz(x) (int) (x).size()
    #define ll long long
    #define ld long double
    #define nl '\n'
    #define sp ' '
    #define fi first
    #define se second
    #define pb push_back
    #define mpr make_pair
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> v, int n, int m) 
    {
        // code here 
        vi res;
        vvb vis(n, vb(m));
        function<void(int, int, int, int)> dfs = [&](int a, int b, int c, int d) {
        	if(a >= n || b < 0 || c >= m || d < 0) return;
        	for(int i=c; i < d; i++) {
        		if(!vis[a][i]) {
        			res.pb(v[a][i]);
        			vis[a][i] = 1;
        		}
        	}
        	for(int i = a + 1; i < b; i++) {
        		if(!vis[i][d-1]) {
        			res.pb(v[i][d-1]);
        			vis[i][d-1] = 1;
        		}
        	}
        	for(int i=d-2; i>=c; i--) {
        		if(!vis[b-1][i]) {
        			res.pb(v[b-1][i]);
        			vis[b-1][i] = 1;
        		}
        	}
        	for(int i=b-2; i>=a+1; i--) {
        		if(!vis[i][c]) {
        			res.pb(v[i][c]);
        			vis[i][c] = 1;
        		}
        	}
    
        	dfs(a + 1, b - 1, c + 1, d-1); 
        };
        dfs(0, n, 0, m);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
