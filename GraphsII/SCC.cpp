#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> temp;
void dfs(int node, vector<vector<int>> &g, vector<int> &stack, vector<bool> &vis, int flag, int cnt = 0) {
    vis[node] = 1;
    if(!flag)  temp.push_back(node);
    for(auto &child: g[node]) {
        if(!vis[child]) {
            dfs(child, g, stack, vis, flag);
        } else {
            if(!cnt) {
                res.push_back(temp);
                cnt = 1;
            }
        }
    }
    if(flag) stack.push_back(node);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // kosaraju implementation
    int n, m;
    cin >> n >> m;
    vector<vector<int>>  g(n);
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<int> stack;
    vector<bool> vis(n, false);

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i, g, stack, vis, 1);
        }
    }
    vector<vector<int>> g_new(n);
    for(int i=0; i<n; i++) {
        for(auto &x: g[i]) {
            g_new[x].push_back(i);
        }
    }

    for(int i=0; i<n; i++) {
        vis[i] = false;
    }
    int scc = 0;
    while(!stack.empty()) {
        int node = stack.back(); stack.pop_back();
        if(!vis[node]) {
            scc++;
            dfs(node, g_new, stack, vis, 0);
            temp.clear();
        }

    }

    cout << scc << '\n';
    for(auto &x: res) {
        for(auto &y: x) cout << y << ' ';
        cout << '\n';
    }


}
