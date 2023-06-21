//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int ok = 0;
        vector<char> color(V, 0);
        function<void(int)> dfs = [&](int x) {
            color[x] = 1;
            for(auto y: adj[x]) {
                if(color[y] == 0) {
                    dfs(y);
                } else if(color[y] == 1) {
                    ok = 1; return;
                }
            }
            color[x] = 2;
        };
        for(int i=0; i<V; i++) {
            if(color[i] == 0) dfs(i);
            if(ok) break;
        }
        return ok;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
