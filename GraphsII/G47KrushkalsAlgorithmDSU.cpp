//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    class DSU {
        public:
        vector<int> size, p;
        DSU(int n) {
            size.resize(n + 1, 1);
            p.resize(n + 1);
            for(int i=0; i<=n; i++) p[i] = i;
        }
        int find(int x) {
            return p[x] = (p[x] == x ? x : find(p[x]));
        }
        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if(x==y) return;
            if(size[x] < size[y]) swap(x, y);
            p[y] = x;
            size[x] += size[y];
        }
    };;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> a;
        for(int i=0; i<V; i++) {
            for(auto &x: adj[i]) {
                a.push_back({x[1],{i, x[0]}});
            }
        }
        DSU dsu(V);
        int sum = 0;
        sort(a.begin(), a.end());
        for(auto &x: a) {
            int wt = x.first, u = x.second.first, v = x.second.second;
            if(dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                sum += wt;
            }
        }
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
