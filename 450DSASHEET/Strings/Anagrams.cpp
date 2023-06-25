class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> res;
        if(m > n) return res;
        vector<int> freqs(26), freqp(26);
        for(int i=0; i<m; i++) {
            ++freqs[s[i]-'a'];
            ++freqp[p[i]-'a'];
        }
        for(int i=m; i<n; i++) {
            if(freqs == freqp) res.push_back(i-m);
            freqs[s[i-m]-'a']--; freqs[s[i]-'a']++;
        }
        if(freqs == freqp) res.push_back(n - m);
        return res;
    }
};
