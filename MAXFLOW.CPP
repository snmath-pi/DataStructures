#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &Rcapacity, unordered_map<int, int> &mp, int source, int sink) {
    unordered_set<int> vis;
    queue<int> q;
    q.push(source);
    vis.insert(source);
    bool foundAugumentedPath = false;
    while(!q.empty()) {
        int u = q.front();
        for(int v = 0; v < Rcapacity.size(); v++) {
            if(vis.count(v) == 0 && Rcapacity[u][v] > 0) {
                mp[v] = u;
                vis.insert(v);
                q.push(v);

                if(v == sink) {
                    foundAugumentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugumentedPath;
}
int maxFlow(vector<vector<int>> &capacity, int source, int sink) {
    int n = capacity.size();
    vector<vector<int>> Rcapacity(n, vector<int>(n,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            Rcapacity[i][j] = capacity[i][j];
        }
    }

    unordered_map<int, int> mp;
    vector<vector<int>> augumented_paths;

    int mxflow = 0;
    while(bfs(Rcapacity, mp, source, sink)) {
        int flow = 1e9;
        vector<int> augumented_path;
        int v = sink;
        while(v != source) {
            augumented_path.push_back(v);
            int u = mp[v];
            if(flow > Rcapacity[u][v]) {
                flow = Rcapacity[u][v];
            }
            v = u;
        }
        augumented_path.push_back(source);
        reverse(augumented_path.begin(), augumented_path.end());
        augumented_paths.push_back(augumented_path);

        mxflow += flow;

        v = sink;
        while(v != source) {
            int u = mp[v];
            Rcapacity[u][v] -= flow;
            Rcapacity[v][u] += flow;
            v = u;
        }
    }

    for(int i=0; i<augumented_paths.size(); i++) {
        cout << i << ": ";
        for(auto &y: augumented_paths[i]) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    return mxflow;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
}
