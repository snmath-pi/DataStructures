class Solution {
public:
    #define ll long long
    ll dp[110][2][2][12];
    const ll mod = 1e9 + 7;
    ll dfs(string &s, ll id = 0, ll flag = 1, ll tight = 1, ll prev = 0) {
        if(id == (ll)s.size()) return !flag;
        if(dp[id][flag][tight][prev] != -1) return dp[id][flag][tight][prev];
        ll res = 0;
        ll lim = (tight == 1 ? (int)(s[id]-'0') : 9);
        for(int i=0; i<=lim; i++) {
            ll t = tight;
            if(tight && i < lim) t = 0;
            ll f = flag;
            if(flag && i > 0) f = 0;

            if(flag) {
                res += dfs(s, id+1,f,t,i); res %= mod;
            } else {
                if(abs(i-prev) == 1) {
                    res += dfs(s, id+1,f,t,i);
                    res %=mod;
                }
            }
        }
        // cout << prev << '\n';
        // cout << res << '\n';
        return dp[id][flag][tight][prev] = res % mod;
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
        // cout << left << ' ';
        memset(dp, -1, sizeof(dp));
        ll u = dfs(left) % mod;
        // cout << high << ' ';
        memset(dp, -1, sizeof(dp));
        ll v = dfs(high) % mod;
        // cout << v << ' ';
        return (v-u+mod)%mod;
    }
};
