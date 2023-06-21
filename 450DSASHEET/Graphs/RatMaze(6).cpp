//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        char direc[] = {'D', 'U', 'R', 'L'};
        vector<vector<bool>> vis(n, vector<bool> (n));
        auto good = [&](int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0);
        };
        function<void(int, int, string)> dfs = [&](int x, int y, string s) {
                
              if(x == n - 1 && y == n-1) {
                  ans.push_back(s);
                  return;
              } 
              vis[x][y] = 1;
              for(int i=0; i<4; i++) {
                  if(good(x + dx[i], y + dy[i]) && m[x + dx[i]][y+dy[i]] ==1) dfs(x + dx[i], y + dy[i], s + direc[i]);
              }
              vis[x][y] = 0;
        };
        if(m[0][0] == 0) return ans;
        dfs(0, 0, "");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
