#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define vb vector<bool>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define tsi set<int>
#define tsl set<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tmii map<int, int>
#define tmll map<ll, ll>
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
 
int t, n, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vi a(n); rep(i, n) cin >> a[i];

    // hashing 
    vi freq(*max_element(all(a)) + 1, 0);
    // or can use hashmaps
    unordered_map<int, int> mp;
    rep(i, n) ++freq[a[i]], ++mp[a[i]];
    int chk = n / k;
    int cntF = 0, cntM = 0;
    rep(i, *max_element(all(a)) + 1) cntF += freq[i] > chk;
    for(auto &x: mp) cntM += x.se > chk;

    cout << cntF << sp << cntM << nl;
    
    // moore voting algorithm could also be used 
    // based on the main idea that number of elements in the array with freq > n / k
    // are atmost k - 1;

}
