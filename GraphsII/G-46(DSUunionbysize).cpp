#include<bits/stdc++.h>
using namespace std;
class dsu {
    vector<int> size, parent;
    int comps;
public:
    dsu(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        comps = n;
        for(int i=0; i<=n; i++) {

            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        comps--;
        if(size[x] < size[y]) {
            parent[x] = parent[y];
        } 
        else {
            parent[y] = parent[x];
            size[x] += size[y];
        }
    }
    int components() {
        return comps;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dsu d(7);
    d.unionBySize(1, 2);
    d.unionBySize(2, 3);
    d.unionBySize(4, 5);
    d.unionBySize(6, 7);
    d.unionBySize(5, 6);
    cout << (d.find(3) == d.find(7) ? "Same": "No") << '\n';
    d.unionBySize(3, 7);
    cout << (d.find(3) == d.find(7) ? "Same": "No") << '\n';

}
