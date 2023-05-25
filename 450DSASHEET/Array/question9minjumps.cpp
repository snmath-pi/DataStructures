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

int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,1,-1,1,-1};

void yesno(bool a) {
    cout << (a?"YES\n":"NO\n");
}
 
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    if(a[0] == 0) {cout << -1 << '\n'; return 0;}
    if(a[0] >= n-1) {cout << 1 << '\n'; return 0;}
    int mx = a[0], step = a[0], jump = 1;
    repn(i, n-1) {
        if(i == n-1) {
            cout << jump << '\n';
            return 0;
        }
        if(a[i] + i >= n - 1) {
            cout << jump + 1 << '\n';
            return 0;
        }
        chkmax(mx, a[i] + i);
        --step;
        if(!step) {
            jump++;
            if(i >= mx) {
                cout << -1 << '\n'; return 0;
            }

            step = mx - i;
        }
    }

    cout << -1 << '\n';
}
