#include<iostream>
#include <vector>
using namespace std;
const int mxN = 200050;
vector<vector<int>> tree(mxN);
const int LG = 21;
int up[mxN][LG];
int depth[mxN];
int vis[mxN];
void dfs(int u) {
    vis[u] = 1;
    for(auto &v: tree[u]) {
        if(!vis[v]) {
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            for(int i=1; i<LG; i++) 
                up[v][i] = up[up[v][i-1]][i-1];
            
            dfs(v);
        }
    }
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];

    for(int i=0; i<LG; i++) {
        if((k>>i) & 1) 
            a = up[a][i];
    }
    if(a == b) 
        return a;

    for(int i=LG-1; i>=0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main() {

    int n, q;
    cin >> n >> q;
    
    for(int i=0, u, v; i<n-1; i++) {
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0);
    
    for(int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int l = lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[l] << '\n';
    }
}
