class Solution {
public:
    void dfs(int id, vector<int> &a, vector<int> &temp, vector<vector<int>> &res) {         
        res.push_back(temp);
        for(int i=id; i<a.size(); i++) {
            if(id < i && a[i] == a[i-1]) continue;
            temp.push_back(a[i]);
            dfs(i + 1, a, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, nums, temp, res);
        return res;
    }
};
