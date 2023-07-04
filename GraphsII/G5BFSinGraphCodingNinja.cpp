#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<set<int>> g(vertex);
    for(auto &x: edges) {
        g[x.first].insert(x.second);
        g[x.second].insert(x.first);
    }
    vector<bool> seen(vertex, false);
    vector<int> res;
    for(int i=0; i<vertex; i++) {
        if(!seen[i]) {
            queue<int> q;
            q.push(i);
            seen[i] = 1;
            res.push_back(i);
            while(!q.empty()) {
                int x = q.front(); q.pop();
                for(auto &y: g[x]) {
                    if(!seen[y]) {
                        q.push(y);
                        seen[y] = 1;
                        res.push_back(y);
                    }
                }
            }
        }
    }
    return res;
}
