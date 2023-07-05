class Solution {
private:
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
int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = sz(mat), m = sz(mat[0]);
        vvb seen(n, vb(m, 0)); vvi res(n, vi(m, 0));
        queue<pair<pii, int>> q;
        rep(i, n) {
            rep(j, m) {
                if(mat[i][j] == 0) {
                    q.push(mpr(mpr(i,j), 0));
                    seen[i][j] = 1;
                }
            }
        }
        while(!q.empty()) {
            int i = q.front().fi.fi, j = q.front().fi.se, dis = q.front().se;
            q.pop();
            res[i][j] = dis;
            rep(k, 4) {
                int dxi = i + dx4[k], dyi = j + dy4[k];

                if(dxi >= 0 && dxi < n && dyi >= 0 && dyi < m && !seen[dxi][dyi]) {
                    seen[dxi][dyi] = 1;
                    q.push({mpr(dxi, dyi), dis + 1});
                }
            }
        }
        return res;

        
    }
};
