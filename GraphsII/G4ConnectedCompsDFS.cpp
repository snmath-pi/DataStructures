//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> g(V);
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<bool> vis(V, 0);
        int cnt = 0;
        function<void(int)> dfs = [&](int i) {
            vis[i] = 1;
            for(auto &y: g[i]) {
                if(!vis[y]) dfs(y);
            }
        };
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
