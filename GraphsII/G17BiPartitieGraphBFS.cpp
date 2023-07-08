class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        for(int i=0; i<n; i++) {
            if(col[i] == -1) {
                queue<int> q;
                q.push(i);
                col[i] = 0;
                while(!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for(auto y: graph[x]) {
                        if(col[y] == -1) {
                            col[y] = col[x] ^ 1;
                            q.push(y);
                        } else {
                            if(col[y] == col[x]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
