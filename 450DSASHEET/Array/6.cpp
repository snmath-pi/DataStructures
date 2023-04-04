#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;
 
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    // finding union
    // naive way O((n+m)log(n+m)) 
    // insertion in a set takes log(n+m) due to rbT imp.
    // set<int> s;
    // rep(i, n) s.insert(a[i]); rep(j, m) s.insert(b[j]); cout << sz(s) << '\n';

    // O(max(n, m)) 
    // unordered_set<int> s;
    // rep(i, min(n, m)) {
    //     s.insert(a[i]); s.insert(b[i]);
    // }
    // rng(i, min(n, m), max(n, m)) {
    //     if(n == max(n, m)) {
    //         s.insert(a[i]);
    //     } else s.insert(b[i]);
    // }
    // cout << sz(s) << '\n';

    // using map as it stores unique keys only
    // O(m * log(m) + n * log(n))
    // unordered_map<int, int> mp;
    // rep(i, n) {
    //     mp[a[i]]++;
    // }
    // rep(i, m) {
    //     mp[b[i]]++;
    // }

    // for(auto x: mp) {
    //     cout << x.fi << ' ';
    // }
    //
    // Merge Technique
    // only works when both aray are sorted
    // we can use this after 
    // sort(all(a)), sort(all(b))
    // ** DOES NOT HANDLE DUPLICATES PRESENT IN AN ARRAY
    // int i = 0, j = 0;
    // while(i < n && j < m) {
    //     if(a[i] < b[j]) {
    //         cout << a[i] << ' ';
    //         i++;
    //     } else if(a[i] > b[j]) {
    //         cout << b[j] << ' ';
    //         j++;
    //     } else if(a[i] == b[j]) {
    //         cout << a[i] << ' ';
    //         i++;
    //         j++;
    //     }
    // }

    // while(i < n) {
    //     cout << a[i] << ' ';
    //     i++;
    // }
    // while(j < m) {
    //     cout << b[j] << ' ';
    //     j++;
    // }




}
