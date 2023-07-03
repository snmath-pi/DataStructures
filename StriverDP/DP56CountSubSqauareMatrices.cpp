#include <bits/stdc++.h> 
int countSquares(int n, int m, vector<vector<int>> &arr) {
    // Write your code here.

    vector<int> dp(m, 0), ndp(m, 0);
    for(int i=0; i < m; i++) dp[i] = arr[0][i];
    int ans = accumulate(dp.begin(), dp.end(), 0ll);
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(j == 0) ndp[j] = arr[i][j];
            else {
                if(arr[i][j] == 1) {
                    ndp[j] = 1 + min(ndp[j-1], min(dp[j-1], dp[j]));
                } else ndp[j] = 0;
            }
        }
        swap(dp, ndp);
        ans += accumulate(dp.begin(), dp.end(), 0ll);
    }

    return ans;

}


