class Solution {
public:
    void dfs(int id, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, vector<int> &seen) {
        if(nums.size() == temp.size()) {
            res.push_back(temp);
            return;
        }
        for(int i =0; i<nums.size(); i++) {
            if(!seen[i]) {
                temp.push_back(nums[i]);
                seen[i] = 1;
                dfs(i+1,nums,temp,res, seen);
                temp.pop_back();
                seen[i] = 0;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp, seen(nums.size(), 0);
        dfs(0, nums, temp, res,seen);
        return res;
    }
};
