class Solution {
public:
    

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        int N = image.size();
        int M = image[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int curr_size = 0;
        auto valid = [&](int i, int j) {
            return (i >=0 && i < N && j>=0 && j< M);
        };
        
        function<void(int, int, int, int)> floodfill = [&](int sr, int sc, int color, int F) {
        if( !valid(sr, sc) || image[sr][sc] == color || image[sr][sc] != F) return;
            
            image[sr][sc] = color;
            for(int i=0; i<4; i++) {
                floodfill(sr + dx[i], sc + dy[i], color, F);
            }

        };
        
        int F = image[sr][sc];
        floodfill(sr, sc, color, F);
        return image;
    }
};
