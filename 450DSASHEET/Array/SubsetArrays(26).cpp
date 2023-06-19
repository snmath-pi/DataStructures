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
// O(NLOGN) solution
string isSubsetNLOGN(int a1[], int a2[], int n, int m) {
    multiset<int> ms1, ms2;
    for(int i=0; i<n; i++) ms1.insert(a1[i]);
    for(int i=0; i<m; i++) ms2.insert(a2[i]);
    multiset<int> ms3 = ms2;
    for(auto x: ms2) {
        if(ms1.count(x)) {
            auto itr = ms3.lower_bound(x);
            ms3.erase(itr);
            itr = ms1.lower_bound(x);
            ms1.erase(itr);
        }
    }
    return (ms3.empty() ? "Yes": "No");
}

// O(N)
string isSubsetN(int a1[], int a2[], int n, int m) {
    int i = 0, j = 0;
    sort(a1, a1 + n); sort(a2, a2 + m);
    while(i < n && j < m) {
        if(a1[i] == a2[j]) i++, j++;
        else i++;
    }
  // if someone wanna do it with for loops
  /*
  for(int i=0, j = 0; i<n; i++) {
      j += a1[i] == a2[j];
  }
   */
    return (j == m ? "Yes": "No");
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0); int m;
    cin >> n >> m;

    int a1[n], a2[m];
    rep(i, n) cin >> a1[i];
    rep(i, m) cin >> a2[i];

    cout << isSubsetNLOGN(a1, a2, n, m) << nl;
    cout << isSubsetN(a1, a2, n, m) << nl;

}
