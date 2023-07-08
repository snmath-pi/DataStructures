//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int i, int j, int a, int b,int n, int m, vector<vector<int>>& grid, vector<pair<int, int>> &temp, vector<vector<bool>>& seen) {
        seen[i][j] = 1;
        temp.push_back({i-a, j-b});
        for(int k=0; k<4; k++) {
            int di = dx[k] + i;
            int dj = dy[k] + j;
            if(di >= 0 && di < n && dj >= 0 && dj < m && !seen[di][dj] && grid[di][dj] == 1) {
                dfs(di, dj, a, b, n, m, grid, temp, seen);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), 0));
        set<vector<pair<int, int>>> s;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && !seen[i][j]) {
                    vector<pair<int, int>> temp;
                    dfs(i, j, i, j, n, m, grid, temp, seen);
                    s.insert(temp);
                }
            }
        }
        return (int) s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
