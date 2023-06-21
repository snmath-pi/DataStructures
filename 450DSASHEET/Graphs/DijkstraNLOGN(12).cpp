//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> res(V, 1e9);
        vector<vector<pair<int, int>>> g(V);
        for(int i=0; i<V; i++) {
            if(adj[i].size()) {
                for(auto &x: adj[i]) {
                    g[i].push_back({x[0], x[1]});
                    g[x[0]].push_back({i, x[1]});
                    
                }
            }
        }
        
        priority_queue<pair<int, int>> pq;
        res[S] = 0;
        pq.push({0, S});
        vector<int> used(V, 0);
        while(!pq.empty()) {
            int x = pq.top().second; pq.pop();
            if(used[x]) continue;
            used[x] = 1;
            for(auto &y: g[x]) {
                int b = y.first, u = y.second;
                if(res[x] + u < res[b]) {
                    res[b] = res[x] + u;
                    pq.push({-res[b], b});
                }
            }
            
        }
        return res;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
