//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> g(n + 1);
        for(int i=0; i<m; i++) {
            g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n+1, 1e9);
        dis[1] = 0;
        pq.push({0, 1});
        vector<int> p(n+1, -1);
        while(!pq.empty()) {
            int node = pq.top().second, d = pq.top().first; pq.pop();
            for(auto &child: g[node]) {
                int u = child.first, wt = child.second;
                if(wt + d < dis[u]) {
                    dis[u] = wt + d;
                    p[u] = node;
                    pq.push({dis[u], u});
                }
            }
        }
        if(dis[n] == 1e9) {
            return {-1};
        }
        vector<int> res;
        int pos = n;
        res.push_back(n);
        while(pos != -1) {
            if(p[pos] != -1) res.push_back(p[pos]);
            pos = p[pos];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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
