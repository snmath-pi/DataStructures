#include<bits/stdc++.h>
using namespace std;

struct Centroid {
    int s;
    vector<int> sub;
    vector<vector<int>> tree;
    Centroid(int &n, vector<vector<int>> &adj) {
        s = n;
        sub.resize(n, 1);
        tree = adj;
    }

    int dfs(int u, int par) {

        for(auto &v: tree[u]) {
            if(v != par) 
                sub[u] += dfs(v, u);
        }
        return sub[u];

    }


    int centroid(int u, int p) {
        for (auto v : tree[u]) {
            if (v != p and sub[v] > s/2) 
                return centroid(v, u);
        }

        return u;
    }

    void print() {
        for(auto &x: sub) 
            cout << x << ' ';
    }

};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for(int i=0, u, v; i<n-1; i++) {
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    Centroid ct(n, g);

    ct.dfs(0, -1);

    // ct.print();
    cout << ct.centroid(0, -1) + 1;

}
