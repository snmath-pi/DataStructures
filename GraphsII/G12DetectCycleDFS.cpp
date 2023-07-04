//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    #define fi first
    #define se second
    bool seen[200010];
    bool dfs(int child, int p, vector<int> adj[]) {
        seen[child] = 1;
        for(auto &x: adj[child]) {
            if(!seen[x]) {
                if(dfs(x, child, adj)) return true;
            }
            else if(p != x) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        memset(seen, 0, sizeof(seen));
        for(int i=0; i<V; i++) {
            if(!seen[i]) {
                if(dfs(i, -1, adj)) return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
