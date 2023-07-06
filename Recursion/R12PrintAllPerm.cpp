class Solution {
public:
    void dfs(int id, vector<int> &temp, vector<int> &nums, vector<vector<int>> &res, vector<int> &seen) {
        if(temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!seen[i]) {
                seen[i] = 1;
                temp.push_back(nums[i]);
                dfs(i + 1, temp, nums, res,seen);
                temp.pop_back();
                seen[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp, seen(nums.size(), 0);
        dfs(0, temp, nums, res, seen);
        return res;
    }
};
