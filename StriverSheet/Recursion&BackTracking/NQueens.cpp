class Solution {
private:
    
private:
    void dfs(int id, vector<string> &fill, vector<vector<string>> &res, int n, vector<int> &left, vector<int> &up, vector<int> &lower) {
        if(id == n) {
            res.push_back(fill);
            return;
        }
        for(int row = 0; row < n; row++) {
            if(!left[row] && !up[n-1+(id-row)] && !lower[id+row]) {
                fill[row][id] = 'Q';
                left[row] = 1;
                up[n-1+id-row] = 1;
                lower[id+row] = 1;
                dfs(id + 1, fill, res, n, left, up, lower);
                fill[row][id] = '.';
                left[row] = 0;
                up[n-1+id-row] = 0;
                lower[id+row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> fill(n);
        string s(n, '.');
        for(int i=0; i<n; i++) fill[i] = s;
        vector<int> left(n, 0), up(2 * n - 1, 0), lower(2 * n - 1, 0);
        dfs(0, fill, res, n, left, up, lower);
        return res;
    }
};
