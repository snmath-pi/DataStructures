class Solution {
public:
    void dfs(vector<int> &nums, int i, int n, vector<vector<int>> &res, vector<int> &temp) {
        if(i >= n) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        dfs(nums, i + 1, n, res, temp);
        temp.pop_back();
        dfs(nums, i + 1, n, res, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums, 0, nums.size(), res, temp);
        return res;
    }
};
