#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LG = 21;
vector<int> tree[N];
int up[N][LG];
int depth[N];
int vis[N];
int p[N];
void dfs(int u) {
    vis[u] = 1;
    for(int v: tree[u]) {
        if(!vis[v]) {
            depth[v] = depth[u] + 1;
            up[v][0] = p[v];
            for(int i=LG-1; i>=1; i--) 
                up[v][i] = up[up[v][i-1]][i-1];
            dfs(v);
        }
    }
}

int kthAncestor(int v, int k) {
    if(depth[v] < k) 
        return -1;
    
    for(int i=0; i<LG; i++) {
        if((k>>i) & 1)
            v = up[v][i];
    }
    return v;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    for(int i=0; i<n; i++) {
        cin >> p[i];
        if(i) {
            tree[i].push_back(p[i]);
            tree[p[i]].push_back(i);
        }
    }

    p[0] = 0;
    dfs(0);

    for(int i=0, v, k; i<q; i++) {
        cin >> v >> k;
        cout << kthAncestor(v, k) << '\n';
    }

}
