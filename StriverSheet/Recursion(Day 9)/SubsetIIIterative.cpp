class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i=0; i<(1 << nums.size()); i++) {
            vector<int> temp;
            for(int j=0; j<nums.size(); j++) {
                if((i >> j) & 1) temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
        set<vector<int>> ans;
        for(auto &x: res) {
            ans.insert(x);
        }
        res.clear();
        for(auto &x: ans) {
            res.push_back(x);
        }
        return res;
    }
};
