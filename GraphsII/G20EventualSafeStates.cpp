class Solution {
private:
    bool dfs(int node, vector<bool> &vis, vector<bool> &is_safe, vector<bool> &path_vis, vector<vector<int>> &g) {
        vis[node] = 1;
        path_vis[node] = 1;
        is_safe[node] = 0;
        for(auto x: g[node]) {
            if(!vis[x]) {
                if(dfs(x, vis, is_safe, path_vis, g)) return true;
            } else if(path_vis[x]) return true;
        }
        is_safe[node] = 1;
        path_vis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, 0);
        vector<bool> path_vis(n, 0);
        vector<bool> is_safe(n, 0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, vis, is_safe, path_vis, graph);
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++) if(is_safe[i]) res.push_back(i);
        return res;
    }
};
