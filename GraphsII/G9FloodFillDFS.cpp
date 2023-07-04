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
        function<void(int, int)> dfs = [&](int i, int j) {
            
            image[i][j] = newColor;
            for(int k = 0; k < 4; k++) {
                if(good(i + dx[k], j + dy[k])) dfs(i + dx[k], j + dy[k]);
            }
        };
        
        dfs(sr, sc);
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
