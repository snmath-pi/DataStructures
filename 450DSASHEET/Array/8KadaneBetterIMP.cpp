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
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll sum = 0, lst = a[0], ans_l = 0, ans_r = 0, minus_pos = -1;
    rep(r, n) {
        sum += a[r];
        if(sum > lst) {
            lst = sum;
            ans_l = minus_pos + 1;
            ans_r = r;
        } 
        if(sum < 0) {
            sum = 0;
            minus_pos = r;
        }
    } 

    cout << sum << "Start: " << ans_l << " End: " << ans_r << '\n';
}
