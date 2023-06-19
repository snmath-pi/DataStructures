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
int longest_consequitive_seqONspace(vi &a) {
    set<int> s(all(a));
    vi b; for(auto &x: s) b.pb(x);
    int m = sz(b);
    int mx = 1;
    rep(i, m) {
        int s = b[i], j = i;
        while(i < m && b[i] == s) i++, s++;
        i--;
        mx = max(mx, i - j + 1);
    }
    return mx;
}
int longest_consequitive_seqO1space(vi &a) {
    int mx = 1, cnt = 1;
    sort(all(a));
    for(int i=1; i<n; i++) {
        if(a[i] - a[i-1] == 1) cnt++;
        else if(a[i] == a[i-1]) continue;
        else {
            mx = max(mx, cnt); cnt = 1;
        }
    }
    mx = max(mx, cnt);
    return mx;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vi a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cout << longest_consequitive_seqONspace(a) << nl;
    cout << longest_consequitive_seqO1space(a) << nl;

}
