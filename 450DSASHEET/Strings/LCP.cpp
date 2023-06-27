class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = ""; int idx = 0;
        while(true) {
            int ok = 0;
            for(char c = 'a'; c <= 'z'; c++) {
                int temp = 1;
                for(auto &x: strs) {
                    if(idx >= x.length()) return res;
                    if(x[idx] != c) {
                        temp = 0; break;
                    }
                }
                if(temp == 1) {
                    ok = 1;
                    res += c;
                }
            }
            if(!ok) return res;
            else idx++;
        }
    }
};
