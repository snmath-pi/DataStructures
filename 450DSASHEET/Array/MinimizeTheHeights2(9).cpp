#include <bits/stdc++.h>

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
#define sz(x) (int) (x).size()
#define ll long long
#define ld long double
#define nl '\n'
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;

template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}

void yesno(bool a) {
    cout << (a?"YES\n":"NO\n");
}
 
int t, n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    // first way to do this->
    sort(all(a));
    int mn = a[0], mx = a[n-1], res = mx - mn;
    repn(i, n-1) {
        if(a[i] - k < 0) continue;
        mn = min(a[0] + k, a[i] - k);
        mx = max(a[i-1] + k, a[n-1] - k);
        chkmin(res, mx - mn);
    }
    cout <<res << '\n';


    // second way is to move the elements near to average val;
    int avg = (mx + mn) >> 1;
    int ret = mx - mn;
    rep(i, n) {
        if(a[i] <= avg) {
            a[i] += k;
        } else a[i] -= k;
    }
    sort(all(a));
    chkmin(ret, a[n-1] - a[0]);
    cout << ret << '\n';

}
