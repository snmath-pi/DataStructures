//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    public:
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

  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> res;
        dsu d(n * m);
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        auto good = [&](int i, int j) {
            return (i >=0 && i < n && j >=0 && j < m);  
        };
        for(auto &x: operators) {
            int row = x[0], col = x[1];
            if(vis[row][col]) {
                res.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            for(int k=0; k<4; k++) {
                int newrow = row + dx[k], newcol = col + dy[k];
                if(good(newrow, newcol)) {
                    if(vis[newrow][newcol] == 1) {
                        int node = row * m + col;
                        int newnode = newrow * m + newcol;
                        if(d.find(node) != d.find(newnode)) {
                            cnt--;
                            d.unionBySize(node, newnode);
                        }
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
