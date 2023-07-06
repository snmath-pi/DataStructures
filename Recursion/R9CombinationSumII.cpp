class Solution {
public:
    void dfs(int id, vector<int> &a, vector<int> &temp, vector<vector<int>> &res, int target) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        for(int i=id; i<a.size(); i++) {
            if(i != id && a[i-1] == a[i]) continue;
            if(a[i] <= target) {
                temp.push_back(a[i]);
                dfs(i + 1, a, temp, res, target-a[i]);
                temp.pop_back();
            } else break;
           
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, candidates, temp, res, target);
        return res;
    }
};
