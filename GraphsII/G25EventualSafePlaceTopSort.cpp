class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> g(n);
        for(int i=0; i<n; i++) {
            for(auto &x: graph[i]) {
                g[x].push_back(i);
            }
        }
        vector<int> ind(n, 0);
        for(int i=0; i<n; i++) {
            for(auto &x: g[i]) ind[x]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(ind[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            res.push_back(node);
            for(auto &child: g[node]) {
                ind[child]--;
                if(ind[child] == 0) q.push(child);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
