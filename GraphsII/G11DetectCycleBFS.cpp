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
        
        vector<bool> seen(V, false);
        for(int i=0; i<V; i++) {
            if(!seen[i]) {
                queue<pair<int, int>> q;
                q.push({i, -1});
                seen[i] = 1;
                while(!q.empty()) {
                    int child = q.front().first, parent = q.front().second;
                    q.pop();
                    for(auto &y: adj[child]) {
                        if(!seen[y]) {
                            q.push({y, child});
                            seen[y] = 1;
                        } else if(parent != y) {
                            return true;
                        }
                    }
                }
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
