//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {source.first, source.second}});
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[source.first][source.second] = 0;
        while(!pq.empty()) {
            int i = pq.front().second.first, j = pq.front().second.second, d = pq.front().first;
            pq.pop();
            for(int k = 0; k<4; k++) {
                int di = i + dx[k], dj = j + dy[k];
                if(di >= 0 && di < n && dj >= 0 && dj < m && grid[di][dj] ==1 && dis[di][dj] < d + 1) {
                     {
                        dis[di][dj] = d + 1;
                        if(di == destination.first && dj == destination.second) return dis[di][dj];
                        
                        pq.push({dis[di][dj], {di, dj}});
                    }
                }
            }
        }
        return -1;
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
