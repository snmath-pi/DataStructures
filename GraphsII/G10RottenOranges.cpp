//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        bool seen[n][m]; int tot = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    seen[i][j] = 2;
                    q.push({{i, j}, 0});
                } else seen[i][j] = 0;
                if(grid[i][j] == 1) tot++;
            }
        }
        int tm = 0;
        int cnt  = 0;
        while(!q.empty()) {
            int i = q.front().first.first, j = q.front().first.second, t = q.front().second; q.pop();
            tm = max(tm, t);
            for(int k=0; k<4; k++) {
                int di = i + dx[k], dj = j + dy[k];
                if(di >= 0 && di < n && dj >=0 && dj < m && seen[di][dj] == 0 && grid[di][dj] == 1) {
                    q.push({{di, dj}, t + 1});
                    seen[di][dj] = 2;
                    cnt++;
                }
            }
        }
        if(cnt != tot) return -1;
        return tm;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
