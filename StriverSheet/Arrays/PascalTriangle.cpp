class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> a = {1};
        vector<int> b = {1, 1};
        res.push_back(a);
        if(numRows == 1) return res;
        res.push_back(b);
        for(int i=2; i<numRows;i++) {
            vector<int> now;

            now.push_back(b[0]);
            for(int i=0; i<b.size(); i++) {
                if(i + 1 < b.size()) {
                    now.push_back(b[i] + b[i+1]);
                } else now.push_back(b[i]);
            }
            res.push_back(now);
            b = now;
        }
        return res;
    }
};
