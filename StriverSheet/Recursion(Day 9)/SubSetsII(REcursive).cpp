class Solution {
private:
    void dfs(int i, vector<int> &nums,  vector<int> &temp, vector<vector<int>> &res) {
        res.push_back(temp);
        for(int j=i; j<nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1]) continue;
            temp.push_back(nums[j]);
            dfs(j + 1, nums,temp, res);
            temp.pop_back();
        }
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(0, nums, temp, res);
        return res;
    }
};
