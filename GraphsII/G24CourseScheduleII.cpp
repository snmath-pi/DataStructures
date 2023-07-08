class Solution {
public:
    bool dfs(int node, vector<int> &res, vector<vector<int>> &g, vector<bool> &vis, vector<bool> &path) {
        vis[node] = 1;
        path[node] = 1;
        for(auto &child: g[node]) {
            if(!vis[child]) 
                if(dfs(child, res, g, vis, path)) {
                    return true;
                }
            if(path[child] == 1) {
                return true;
            }
        }
        res.push_back(node);
        path[node] = 0;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for(int i=0; i<prerequisites.size(); i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> path(n, 0);
        vector<int> res;
        vector<bool> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i, res, g, vis, path)) {
                    return {};
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
