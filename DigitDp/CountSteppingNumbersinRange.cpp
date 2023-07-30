class Solution {
public:
    #define ll long long
    ll dp[110][2][2];
    const ll mod = 1e9 + 7;
    long long dfs(string s, ll id, ll flag = 0, ll tight = 1) {
        if(id == s.size()) return flag;
        if(dp[id][flag][tight] != -1) return dp[id][flag][tight];
        if(tight) {
            
        }
        ll res = 0;
        for(int i=0; i<=9; i++) {
            res += dfs()
        }
    }
    int countSteppingNumbers(string low, string high) {
        reverse(low.begin(), low.end());
        int x = (low[0]-'0') - 1, carry;
        string left;
        if(x < 0) x += 10, carry = 1;
        else carry = 0;
        left += (x + '0');
        for(int i=1; i<low.size(); i++) {
            int x = (low[i] - '0') -carry;
            if(x < 0) x += 10, carry = 1;
            else carry = 0;
            left += (x + '0');
        }
        reverse(left.begin(), left.end());
        cout << left << ' ';
        memset(dp, -1, sizeof(dp));
        ll u = dfs(left, 0) % mod;
        memset(dp, -1, sizeof(dp));
        ll v = dfs(high, 0) % mod;
        
        return (v-u+mod)%mod;
    }
};
