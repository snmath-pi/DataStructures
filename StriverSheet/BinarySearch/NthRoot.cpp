#include<bits/stdc++.h>
using namespace std;

double dfs(double mid, double n, double m) {
    double ans = 1.0;
    for(int i=1; i<=n; i++) {
        ans = ans * mid;
        if(ans >= m)return false;
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;

    double l = 1, r = m;
    double eps = 1e-6;
    while(r - l > eps) {
        double mid = (l + r) / 2.0;
        if(dfs(mid, n, m)) l = mid;
        else r = mid;
    }
    cout << l << " " << r << '\n';
}
