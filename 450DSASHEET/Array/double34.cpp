#include <algorithm>
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

ld O_N(vi &a, vi &b) {
    vi c; int i = 0, j = 0;
    while(i < n && j < n) {
        if(a[i] <= b[j]) {c.pb(a[i++]);}
        else c.pb(b[j++]);
    }
    while(i < n) c.pb(a[i++]);
    while(j < n) c.pb(b[j++]);
    debug(c);
    if(sz(c)%2) {
        return c[sz(c) / 2];
    } else {
        return (ld) (c[sz(c)/2] + c[sz(c)/2 - 1]) / 2.0;
    }
    return 0.0;
}

ld O_LOGN(vi &a, vi&b) {
    int start = 0, end = n;
    int tot = (n + n + 1) / 2;
    while(start <= end) {
        int m = start + end >> 1, la = m, ba = tot - m;
        int w = la ? a[la-1] : -1e9, x = ba ? b[ba-1] : -1e9,
        y = la < n ? a[la] : 1e9, z = ba < n ? b[ba] : 1e9;
        if(w <= z && x >= y) {
            return (ld) (max(w, x) + min(y, z)) / 2.0;
        
        } else if(w > z) end = m - 1;
        else start = m + 1;
    }
    return 0.0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vi b(n); rep(i, n) cin >> b[i];

    cout << O_N(a, b) << nl;
    cout << O_LOGN(a, b) << nl;

}
