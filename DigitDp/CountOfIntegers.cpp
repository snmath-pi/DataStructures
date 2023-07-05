//link: https://leetcode.com/problems/count-of-integers/
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
    string chk(string a, string b = "1") {
        string res = "";
        int n = a.length();
        reverse(a.begin(), a.end());
        int carry = 0;
        for(int i=0; i<1; i++) {
            int sub = ((a[i] -'0') - (b[i]-'0')-carry);
            if(sub < 0) {
                sub += 10;
                carry = 1;
            } else carry = 0;
            res.push_back(sub + '0');
        }
        for(int i=1; i<n; i++) {
            int sub = ((a[i]-'0')-carry);
            if(sub < 0) {
                sub += 10;
                carry = 1;
            } else carry = 0;
            res.push_back(sub + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        num1 = chk(num1);
        ll res1 = dfs(num1, min_sum, max_sum) % mod;
        memset(dp, -1, sizeof(dp));
        ll res2 = dfs(num2, min_sum, max_sum) % mod;
        return (res2 - res1 + mod) % mod;
    }
};
