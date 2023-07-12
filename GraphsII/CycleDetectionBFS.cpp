#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> g(n);
    for(auto &e: edges) {
        e[0]--, e[1]--;
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    vector<int> vis(n, 0);
    vector<int> parent(n, -1);
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            queue<int> q;
            vis[i] = 1;
            q.push(i);
            while(!q.empty()) {
                int node = q.front(); q.pop();
                for(auto &child: g[node]) {
                    if(!vis[child]) {
                        parent[child] = node;
                        vis[child] = 1;
                        q.push(child);
                    } else {
                        if(parent[node] != child) return "Yes";
                    }
                }
            }
        }
    }
    return "No";
}

