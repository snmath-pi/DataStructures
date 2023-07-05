class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, 0));
        auto good = [&](int i, int j) {
            return (i >= 0 && i < n && j >=0 && j <m && !seen[i][j] && grid[i][j] == 1);
        };

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        function<void(int, int)> dfs = [&](int i, int j) {
            if(!good(i, j)) return;
            seen[i][j] = 1;
            for(int k=0; k<4; k++) {
                dfs(i + dx[k], j + dy[k]);
            }
        };

        int q = 0;
        for(int cnt = 0; cnt < 2; cnt++) {
            for(int j=0; j<m; j++) {
                if(!seen[q][j] && grid[q][j] == 1) dfs(q, j);
            }
            q = n-1;
        }

        q = 0;
        for(int cnt = 0; cnt < 2; cnt++) {
            for(int i=0; i<n; i++) {
                if(!seen[i][q] && grid[i][q] == 1) dfs(i, q);
            }
            q = m-1;
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++)
                if(grid[i][j] == 1 && !seen[i][j]) cnt++;
        }

        return cnt;

    }
};
