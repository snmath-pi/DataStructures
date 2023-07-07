class Solution {
public:
    bool chkpalindrome(string s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        } return true;
    }
    void dfs(int id, string &s, vector<vector<string>> &res, vector<string>&taken) {
        if(id == s.size()) {
            res.push_back(taken);
            return;
        }
        for(int i=id; i<s.size(); i++) {
            if(chkpalindrome(s, id, i)) {
                taken.push_back(s.substr(id, i - id + 1));
                dfs(i+1, s, res, taken);
                taken.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> taken;
        dfs(0, s, res, taken);
        return res;
    }
};
