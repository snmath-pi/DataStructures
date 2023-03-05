/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
// Question: https://atcoder.jp/contests/abc292/tasks/abc292_d
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
struct DSU {
    int comps;
    vector<int> par, sz, es;
    DSU(int x) {
        par.resize(x); sz.resize(x), es.resize(x);
        comps = x;
        for(int i=0; i<x; i++) {
            par[i] = i;
            sz[i] = 1;
            es[i] = 0;
        }

    }
    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) {
            es[a]++;
            return;
        }
        if(sz[a] < sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        es[a] += es[b] + 1;
        comps--;
    }
    bool same(int i, int j) {return find(i) == find(j);}
    int size(int x) {return sz[find(x)];}
    int edges(int x) {return es[find(x)];};
    int components()  {return comps;}

};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    DSU d(N);
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        d.unite(a, b);
    }
    for(int i=0; i<N; i++) {
        if(d.edges(i) != d.size(i)) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
