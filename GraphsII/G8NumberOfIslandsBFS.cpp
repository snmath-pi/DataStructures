//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool> (m, false));
        auto good = [&](int i, int j) {
            return (i >= 0 && i < n && j >=0 && j < m && grid[i][j] == '1' && !seen[i][j]);
        };
        
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' && !seen[i][j]) {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    seen[i][j] = 1;
                    while(!q.empty()) {
                        int u = q.front().first, v = q.front().second; q.pop();
                        for(int i=0; i<8; i++) {
                            int di = u + dx[i];
                            int dj = v + dy[i];
                            if(good(di, dj)) {
                                seen[di][dj] = 1;
                                q.push({di, dj});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
