class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.length() < s.length()) return 0;
        s = s + s;
        int n = s.length();
        int m = goal.length(), j = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == goal[j]) {
                while(i < n && j < m && s[i] == goal[j]) i++, j++;
                if(j == m) {
                    return 1;
                } else j =0, i--;
            }
        }
        return 0;
    }
};
