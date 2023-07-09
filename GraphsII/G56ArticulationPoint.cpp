//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    private:
        int timer  = 0;
        void dfs(int node, int parent, vector<int> &vis, vector<int> &low, vector<int> &tin, vector<int> &mark, vector<int> adj[]) {
            vis[node] = 1;
            tin[node] = low[node] = timer; timer++;
            int c = 0;
            for(auto &child: adj[node]) {
                if(child == parent) continue;
                if(!vis[child]) {
                    dfs(child, node, vis, low,tin,mark,adj);
                    low[node] = min(low[node], low[child]);
                    if(low[child] >= tin[node] && parent != -1) {
                        mark[node] = 1;
                    }
                    c++;
                } else {
                    low[node] = min(low[node], tin[child]);
                }
            }
            if(c > 1 && parent == -1) {
                mark[node] = 1;
            }
        }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> vis(n, 0);
        vector<int> tin(n, 0), low(n, 0);
        vector<int> mark(n, 0);
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis,low,tin,mark,adj);
            }
        }
        for(int i=0; i<n; i++) {
            if(mark[i]) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
