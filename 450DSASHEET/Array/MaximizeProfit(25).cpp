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
    cin >> n; vi a(n);
    rep(i, n) cin >> a[i];
    vi profit(n, 0);
    int max_price = a[n-1];

    for(int i=n-2; i>=0; i--) {
        if(a[i] > max_price) max_price = a[i];
        profit[i] = max(profit[i+1], max_price - a[i]);
    }

    // now for the front iteration store min price
    int min_price = a[0];
    for(int i=1; i<n; i++) {
        if(a[i] < min_price) min_price = a[i];
        profit[i] = max(profit[i-1], profit[i] + a[i] - min_price);
    }
    cout << profit[n-1] << nl;
}
