class Solution {
public:
    void dfs(int id, vector<int> &nums, vector<vector<int>> &res) {
        if(id == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=id; i<nums.size(); i++) {
            swap(nums[i], nums[id]);
            dfs(id + 1, nums, res);
            swap(nums[i], nums[id]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
};
