//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
        
    void topsort(int node, vector<int> &vis, vector<int> &res, vector<pair<int, int>> g[]) {
        vis[node] = 1;
        for(auto &child: g[node]) {
            if(!vis[child.first]) {
                topsort(child.first, vis, res, g);
            }
        }
        res.push_back(node);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> g[N];
        for(int i=0; i<M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            g[u].push_back({v, wt});
        }
        vector<int> vis(N, 0);
        vector<int> res;
        for(int i=0; i<N; i++) {
            if(!vis[i]) {
                topsort(i, vis, res, g);
            }
        }
        const int inf = 1e9 + 7;
        vector<int> dis(N, inf);
        dis[0] = 0;
        while(!res.empty()) {
            int node = res.back();
            res.pop_back();
            for(auto &child: g[node]) {
                if(dis[node] + child.second < dis[child.first]) {
                    dis[child.first] = dis[node] + child.second;
                }
            }
        }
        for(int i=0; i<N; i++) {
            if(dis[i] == 1e9 + 7) dis[i] = -1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
