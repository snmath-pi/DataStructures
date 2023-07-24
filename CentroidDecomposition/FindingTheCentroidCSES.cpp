#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    vector<int> p(n+1, -1);
    for(int i=0, u, v; i<n-1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n+1, 0);
    function<void(int, int)> dfs2 = [&](int node, int par) {
        vis[node] = 1;
        p[node] = par;
        for(auto &x: g[node]) {
            if(!vis[x]) {
                dfs2(x, node);
            }
        }
    };
    dfs2(1, -1);
    vector<int> dp(n+1, 1);
    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for(auto &child: g[node]) {
            if(!vis[child]) {
                dfs(child);
                dp[node] += dp[child];
            }
        }
    };
    vis.assign(n + 1, 0);
    dfs(1);

    for(int i=1; i<=n; i++) {
        vector<int> temp;
        for(auto &x: g[i]) {
            if(p[i] == x) {
                continue;
            }
            else {
                temp.push_back(dp[x]);
            }
        }
        int cur = n - accumulate(temp.begin(), temp.end(), 0) - 1;
        temp.push_back(cur);
        bool ok = true;
        for(auto &x: temp) {
            if(x > n / 2) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << i;
            return 0;
        }
    }



}
