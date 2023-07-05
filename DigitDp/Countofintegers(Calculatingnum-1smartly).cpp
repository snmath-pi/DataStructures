class Solution {
public:
    #define ll long long
    ll dp[26][210][2];
    const ll mod = 1e9 + 7;
    ll dfs(string s, int &mn, int &mx, ll pos = 0, ll sum = 0, ll tight=1) {
        if(pos == s.length()){
            return (sum <= mx && sum >= mn) % mod;
        }
        if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight] % mod;
        if(tight) {
            ll res = 0;
            for(ll i=0; i<=s[pos]-'0';i++){
                if(i == s[pos]-'0') {
                    res = (res % mod + dfs(s, mn, mx, pos + 1, sum + i, 1)% mod) % mod;
                } else {
                    res = (res %mod + dfs(s, mn, mx, pos +1, sum + i, 0) % mod) % mod;
                }
            }
            return dp[pos][sum][tight] = res % mod;
        }
        ll res = 0;
        for(ll i =0; i<=9; i++) {
            res = (res % mod + dfs(s, mn, mx, pos +1,sum+i,0)%mod)%mod;
        }
        return dp[pos][sum][tight]=res%mod;

    }
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        int n = num1.length()-1;
        while(num1[n] == '0')n--;
        num1[n++]--;
        while(n<num1.length()) num1[n++] = '9';
        ll res1 = dfs(num1, min_sum, max_sum) % mod;
        memset(dp, -1, sizeof(dp));
        ll res2 = dfs(num2, min_sum, max_sum) % mod;
        return (res2 - res1 + mod) % mod;
    }
};
