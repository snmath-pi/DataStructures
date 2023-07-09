//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        // Code here
        int dx[4] = {1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int n = grid.size(), m = grid[0].size();
        
        auto good = [&](int i, int j) {
            return (i >=0 && i <n && j>=0 && j<m);
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,0}});
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first, c = it.second.second;
            if(r == n-1 && c == m-1) return diff;
            for(int k=0; k<4; k++) {
                int newr = dx[k] + r, newc = dy[k] + c;
                if(good(newr, newc)) {
                    int neweffort = max(abs(grid[newr][newc] - grid[r][c]), diff);
                    if(neweffort < dis[newr][newc]) {
                        dis[newr][newc] = neweffort;
                        pq.push({dis[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
