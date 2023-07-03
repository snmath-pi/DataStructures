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

ll dfs(int i, int buy, vvl &dp, vl &a, int &n) {
    if(i == n) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    ll profit;
    if(buy) {
        profit = max(-a[i] + dfs(i + 1, 0, dp, a, n), dfs(i+1, 1, dp, a, n));
    } else {
        profit = max(a[i] + dfs(i+1, 1, dp, a, n), dfs(i+1, 0, dp, a, n));
    }
    return dp[i][buy] = profit;
}

ll dfs(int i, int buy, int cap, vector<vvl> &dp, vl &a, int n) {
    if(i == n || cap == 0) return 0;
    if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
    ll profit;
    if(buy) {
        profit = max(-a[i] + dfs(i +1,0,cap,dp, a,n), dfs(i+1,1,cap,dp,a,n));
    } else {
        profit = max(a[i] + dfs(i+1,1,cap-1,dp,a,n), dfs(i+1,0,cap,dp,a,n));
    }

    return dp[i][buy][cap] = profit;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vl a(n);
    rep(i, n) cin >> a[i];
    // ~ memoization
    // vector<vvl> dp(n, vvl(2, vl(k + 1, -1)));

    // cout << dfs(0, 1, k, dp, a, n);

    // ~tabulation
    // vector<vvl> dp(n + 1, vvl(2, vl(k + 1, 0)));

    // per(i, n) {
    //     rep(j, 2) {
    //         repn(u, k) {
    //             ll profit = 0;
    //             if(j == 1) {
    //                 profit = max(-a[i] + dp[i+1][0][u], dp[i+1][1][u]);
    //             } else {
    //                 profit = max(a[i] + dp[i+1][1][u-1], dp[i+1][0][u]);
    //             }
    //             dp[i][j][u] = profit;
    //         }
    //     }
    // }

    // cout << dp[0][1][k] << nl;


    // ~space optimizzation
    vvl dp(2, vl(k + 1, 0)), ndp(2, vl(k + 1, 0));
    per(i, n) {
        rep(j, 2) {
            repn(u, k) {
                ll profit = 0;
                if(j == 1) {
                    profit = max(-a[i] + dp[0][u], dp[1][u]);
                } else {
                    profit = max(a[i] + dp[1][u-1], dp[0][u]);
                }
                ndp[j][u] = profit;
            }

        }
        swap(dp, ndp);
    }

    cout << dp[1][k] << nl;


}
