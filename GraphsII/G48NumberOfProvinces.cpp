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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        dsu d(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j) {
                    if(isConnected[i][j]) {
                        d.unionBySize(i, j);
                    }
                }
            }
        }
        return d.components();
    }
};
