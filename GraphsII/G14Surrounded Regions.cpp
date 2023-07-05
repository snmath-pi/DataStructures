class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, 0));
        auto good = [&](int i, int j) {
            return (i >= 0 && i < n && j >=0 && j < m && !seen[i][j] && board[i][j] == 'O');
        };
        function<void(int, int)> dfs = [&](int i, int j) {
            if(!good(i, j)) return;
            seen[i][j] = 1;
            for(int k=0; k<4; k++) {
                dfs(i + dx[k], j + dy[k]);
            }
        };
        int q = 0;
        for(int i=0; i<2; i++) {
            for(int j = 0; j<m; j++) {
                if(!seen[q][j] && board[q][j] == 'O') {
                    dfs(q, j);
                }
            }
            q = n-1;

        }
        q = 0;
        for(int i=0; i<2; i++) {
            for(int j = 0; j<n; j++) {
                if(!seen[j][q] && board[j][q] == 'O') {
                    dfs(j, q);
                }
            }
            q = m-1;

        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && !seen[i][j] ) board[i][j] = 'X';
            }
        }

    }
};
