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
        set<pair<int, int>> s;
        vector<int> dis(V);
        for(int i=0; i<V; i++) {
            dis[i] = INT_MAX;
        }
        s.insert({0, S});
        // set can be used to erase already used bad paths
        dis[S] = 0;
        while(!s.empty()) {
            auto it = *(s.begin());
            int node = it.second, wt = it.first;
            s.erase(it);
            for(auto &child: adj[node]) {
                int u = child[0], d = child[1];
                if(d + wt < dis[u]) {
                    if(dis[u] != INT_MAX) {
                        s.erase({dis[u], u});
                    } 
                    dis[u] = d + wt;
                    s.insert({dis[u], u});
                }
            }
        }
        return dis;
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
