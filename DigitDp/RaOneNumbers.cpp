// link: https://www.spoj.com/problems/RAONE/
#include <algorithm>
#include <stack>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define gnr(i,a,b) for(int i=b-1;i>=a;--i)
#define vb vector<bool>
#define vi vector<int>
#define vl vector<ll>
#define vvb vector<vb>
#define vvi vector<vi>
#define vvl vector<vl>
#define si unordered_set<int>
#define sl unordered_set<ll>
#define tsi set<int>
#define tsl set<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define tmii map<int, int>
#define tmll map<ll, ll>
#define mii unordered_map<int, int>
#define mll unordered_map<ll, ll>
#define pqi priority_queue<int>
#define pqig priority_queue<int, vi, greater<int>>
#define pql priority_queue<ll>
#define pqlg priority_queue<ll, vl, greater<ll>>
#define pqpii priority_queue<pii>
#define pqpll priority_queue<pll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()
#define ll long long
#define ld long double
#define nl '\n'
#define sp ' '
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << sp; use_(x); cerr << nl;
#else
#define debug(x)
#endif

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};
int dx8[8]={0,1,0,-1,1,1,-1,-1};
int dy8[8]={1,0,-1,0,1,-1,1,-1};

void yesnoc(bool a) {
    cout << (a? "YES\n": "NO\n");
}
void yesnos(bool a) {
    cout << (a? "Yes\n": "No\n");
}

void use_(ll W) {cerr << W;}
void use_(ld W) {cerr << W;}
void use_(char W) {cerr << W;}
void use_(string W) {cerr << W;}
void use_(int W) {cerr << W;}
void use_(double W) {cerr << W;}

template<typename T, typename V> void use_(pair<T, V> p) {
    cerr << "["; use_(p.fi); cerr << ','; use_(p.se); cerr << ']';
}
template<typename T> void use_(vector<T> a) {
    cerr << '['; for(T i: a) { use_(i); cerr << sp;
    } cerr << ']'; cerr << nl;
}
template<typename T> void use_(set<T> a) {
    cerr << '['; for(T i: a) { use_(i); cerr << sp;
    } cerr << ']'; cerr << nl;
}
template<typename T> void use_(multiset<T> ms) {
    cerr << '['; for(T i: ms) { use_(i); cerr << sp;
    } cerr << ']'; cerr << nl;
}
template<typename T, typename V> void use_(map<T, V> mp) {
    cerr << '[';  for(auto x: mp) { use_(x.fi); cerr << ','; 
        use_(x.se); cerr << sp;
    } cerr << ']'; cerr << nl;
}
 
int t, n, k;
ll dp[12][100][100][2];
ll dfs(string s, ll pos = 0, ll sume = 0, ll sumo = 0, ll tight = 1) {
    if(pos == s.length()) {
        if(s.length() % 2 == 0) return sume - sumo == 1;
        else return sumo - sume == 1;    
    }

    if(dp[pos][sume][sumo][tight] != -1) return dp[pos][sume][sumo][tight];
    if(tight) {
        ll res = 0;
        for(int i=0; i<=s[pos]-'0'; i++) {
            if(i == s[pos]-'0') {
                if(pos % 2 == 0) {
                    res += dfs(s, pos + 1, sume + i, sumo, 1);
                } else {
                    res += dfs(s, pos + 1, sume, sumo + i, 1);
                }
            }
            else {

                if(pos % 2 == 0) {
                    res += dfs(s, pos + 1, sume + i, sumo, 0);
                } else {
                    res += dfs(s, pos + 1, sume, sumo + i, 0);
                }
            }
        }
        return dp[pos][sume][sumo][tight] = res;
    }
    ll res = 0;
    for(int i=0; i<=9; i++) {
        if(pos % 2 == 0) {
            res += dfs(s, pos + 1, sume + i, sumo, 0);
        } else {
            res += dfs(s, pos + 1, sume, sumo + i, 0);
        }
    }
    return dp[pos][sume][sumo][tight] = res;

}
void solve() {
    ll l, r;
    cin >> l >> r;
    l--;
    string a = to_string(l), b = to_string(r);
    memset(dp, -1, sizeof(dp));
    ll ans1 = dfs(a);
    memset(dp, -1, sizeof(dp));
    ll ans2 = dfs(b);

    cout << ans2 - ans1 << nl;

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1; 
    cin >> tc;
    while(tc--) {
        solve();
    }
    
}
