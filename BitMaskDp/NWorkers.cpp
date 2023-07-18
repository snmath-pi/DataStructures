#include<bits/stdc++.h>
using namespace std;


void add(int &x, int y) {
    x |= (1 << y);
}
void remove(int &x, int y) {
    x ^= (1 << y);
}
void display(int subset) {
    for(int i=9; i>=0; i--) {
        cout << (((subset >> i) & 1) != 0) << ' ';
    }
    cout << '\n';
}

int dfs(int i, int mask, int &n, vector<vector<int>> &dp, vector<vector<int>> &jobs) {
    if(i == n) return 0;
    if(dp[i][mask]  != -1) return dp[i][mask];

    int res = 1e9;
    for(int j = 0; j<n; j++) {
        if((mask >> j) & 1) {
            res = min(res, jobs[j][i] + dfs(i+1, mask ^ (1<<j), n, dp, jobs));
        }
    }
    return dp[i][mask] = res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<int>> jobs(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> jobs[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(1<<n, -1));
    cout << dfs(0, (1 << n)-1, n, dp, jobs);

}
