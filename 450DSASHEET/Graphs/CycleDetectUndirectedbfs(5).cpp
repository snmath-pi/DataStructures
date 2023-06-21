//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    #define fi first
    #define se second
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool> used(V, 0);
        queue<pair<int, int>> q;
        for(int i=0; i<V; i++) {
            if(!used[i]) {
                q.push({i, -1});
                used[i] = 1;
                while(!q.empty()) {
                    auto Y = q.front();
                    q.pop();
                    for(auto &x: adj[Y.fi]) {
                        if(!used[x]) {
                            used[x] = 1;
                            q.push({x, Y.fi});
                        } else if(Y.se != x) {
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
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
