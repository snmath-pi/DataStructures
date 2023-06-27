class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int mn = -2147483647;
        int mx = 2147483647;
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += count(matrix[i].begin(), matrix[i].end(), 0);
        }
        if(!cnt) return;
        int val;
        for(int i=mn; i<=mx; i++) {
            if(i == 0) continue;
            int ok = 1;
            for(int r = 0; r < n; r++) {
                for(int c = 0; c < m; c++) {
                    if(matrix[r][c] == i) {
                        ok = 0; break;
                    }
                }
            }
            if(ok) {
                val = i; break;
            }
        }
        
        int top, right, bottom, left;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(matrix[r][c] == 0) {
                    top = r-1, bottom = r + 1, right = c + 1, left = c - 1;
                    while(top >= 0 || bottom < n) {
                        if(top >=0) {
                            if(matrix[top][c] != 0) matrix[top][c]= val;
                            top--;
                        }
                        if(bottom < n) {
                            if(matrix[bottom][c] != 0) matrix[bottom][c]= val;
                            bottom++;
                        }
                    }
                    while(right < m || left >= 0) {
                        if(left >= 0) {
                            if(matrix[r][left] != 0) matrix[r][left] = val;
                            left--;
                        }
                        if(right < m) {
                            if(matrix[r][right] != 0) matrix[r][right] = val;
                            right++;
                        }
                    }
                }
            }
        }

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(matrix[r][c] == val) matrix[r][c] = 0;
            }
        }
    }
};
