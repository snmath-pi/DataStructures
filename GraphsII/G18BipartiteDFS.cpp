class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(205, -1);
        bool ok = 1;
        function<void(int, int)> dfs = [&](int i, int c){
            color[i] = c;
            for(int y:graph[i]) {
                if(color[y] == -1) {
                    dfs(y, c ^ 1);
                }
                else {
                    if(color[y] == c) ok = false;
                }
            }
        };
        for(int i=0; i<(int)graph.size(); i++) {
            if(color[i] == -1) {
                dfs(i, 0);
            }
        }
        return ok;
    }
};
