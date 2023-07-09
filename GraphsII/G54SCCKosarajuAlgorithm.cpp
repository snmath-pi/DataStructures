//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	
	//Function to find number of strongly connected components in the graph.
	private:
	void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
	    vis[node] = 1;
	    for(auto &child: adj[node]) {
	        if(!vis[child]) {
	            dfs(child,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	private:
	void dfs3(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
	    vis[node] = 1;
	    for(auto &child: adj[node]) {
	        if(!vis[child]) {
	            dfs3(child,vis,adj,st);
	        }
	    }
	}
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        vector<vector<int>> adjT(V);
        for(int i=0; i<V; i++) {
            for(auto &child: adj[i]) {
                adjT[child].push_back(i);
            }
        }
        vis.assign(V, 0);
        int scc = 0;
        while(!st.empty()) {
            int node = st.top(); st.pop();
            if(!vis[node]) {
                dfs3(node, vis, adjT, st);
                scc++;
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
