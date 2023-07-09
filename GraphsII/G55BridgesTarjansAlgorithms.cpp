class Solution {
int timer = 1;
private:
    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj,vector<int> &tin, vector<int> &low, vector<vector<int>> &res) {
        vis[node] = 1;
        tin[node] = low[node] = timer; 
        timer++;
        for(auto &it: adj[node]) {
            if(it == parent) {
                continue;
            }
            if(!vis[it]) {
                dfs(it, node, vis,adj,tin,low,res);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node])  {
                    res.push_back({it, node});
                } 
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> res;
        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        dfs(0,-1,vis,adj,tin,low,res);
        return res;
    }
};
