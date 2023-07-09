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
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();
        dsu d(n);
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++) {
            for(int j=1; j<a[i].size(); j++) {
                string s = a[i][j];
                if(mp.count(s)) {
                    d.unionBySize(i, mp[s]);
                } else mp[s] = i;
            }
        }
        vector<string> res[n];
        for(auto &it: mp) {
            int node = it.second;
            node = d.find(node);
            res[node].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++) {
            if(res[i].size() == 0) continue;
            sort(res[i].begin(), res[i].end());
            vector<string> temp;
            temp.push_back(a[i][0]);
            for(auto &x: res[i]) temp.push_back(x);
            ans.push_back(temp);

        }
        return ans;
    }
};
