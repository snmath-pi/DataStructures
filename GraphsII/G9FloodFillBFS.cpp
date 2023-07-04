//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size(), m = image[0].size();
        
        int col = image[sr][sc];
        auto good = [&](int i, int j) {
            return (i >= 0 && i < n && j >=0 &&  j < m && image[i][j] == col && image[i][j] != newColor);
        };
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()) {
            int u = q.front().first, v = q.front().second; q.pop();
            if(!good(u, v)) continue;
            image[u][v] = newColor;
            for(int i=0; i<4; i++) {
                if(good(u + dx[i], v + dy[i])) q.push({u + dx[i], v + dy[i]});
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
