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
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n - 1) return -1;
        dsu d(n);
        for(auto &x: connections) 
            d.unionBySize(x[0], x[1]);
        return (d.components() == 1 ? 0 : d.components() - 1);

    }
};
