//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  public:
    bool dfs(int i, vector<int> &vis, vector<int> &check, vector<int> &pathvis, vector<int> adj[]) {
        vis[i] = 1;
        check[i] = 0;
        pathvis[i] = 1;
        for(auto &child: adj[i]) {
            if(!vis[child]) {
                if(dfs(child,vis,check,pathvis,adj)) return true;
            } else if(pathvis[child]) {
                check[child] = 0;
                return true;
            }
        }
        check[i] = 1;
        pathvis[i] = 0;
        return false;
        
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> check(n, 0);
        vector<int> res;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, vis, check,pathvis,adj);
            }
        }
        for(int i=0; i<n; i++) {
            if(check[i]) res.push_back(i);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
