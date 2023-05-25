#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define gnr(i,a,b) for(int i=b-1;i>=a;--i)
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

template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

void yesno(bool a) {
    cout << (a?"YES\n":"NO\n");
}
 
int t, n, X;
bool find3Numbers(vi &a, int n, int X){
    unordered_map<int, pair<int, int>> mp; // use unordered map to prevent tle instead of map
    // unordered_map has better O(1) count in best case
    for(int i=0; i<n; i++) {
        mp[a[i]].first++;
        mp[a[i]].second = i;
    }
    for(int i=0; i<n; i++) {
        for(int j = 0; j < n; j++) {
            if(i!=j) {
                int req = X - a[i] - a[j];
                if(req < 0) continue;
                if(mp.count(req)) {
                    if(mp[req].second != i and mp[req].second != j) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> X;
    vi a(n);
    rep(i, n) cin >> a[i];
    cout << find3Numbers(a, n, X);
  


}
