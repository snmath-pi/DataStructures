class Solution {
public:
    void dfs(int id, vector<int> &a, vector<int> &temp, vector<vector<int>> &res, int target) {
        if(target < 0) return;
        if(id == a.size()) {
            if(target == 0) {
                res.push_back(temp);
            }
            return;
        }
        if(a[id] <= target) {
            temp.push_back(a[id]);
            dfs(id, a, temp, res, target-a[id]);
            temp.pop_back();
        }
        dfs(id+1, a, temp,res, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, candidates, temp, res, target);
        return res;
    }
};
