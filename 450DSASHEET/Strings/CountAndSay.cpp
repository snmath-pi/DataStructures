class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if(n == 1) return s;
       
        for(int k=1; k<n; k++) {
            int cnt = 0; string temp = "";
            for(int i=0; i<s.size(); i++) {
                char cur = s[i], cnt = 0;
                while(i < s.size() && s[i] == cur) i++, cnt++;
                temp += (cnt + '0');
                temp += cur;
                i--;
            }
            swap(s, temp);
        }
        return s;
    }
};
