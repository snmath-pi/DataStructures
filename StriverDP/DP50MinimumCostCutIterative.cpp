#include <bits/stdc++.h> 

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(n);
    cuts.push_back(0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int> (c + 2, 0));

    for(int i=c; i >= 1; i--) {
        for(int j=1; j <=c; j++) {
            if(i > j) continue;
            int mn = 1e9;
            for(int k=i; k<=j; k++) {
                mn = min(mn, cuts[j + 1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][c];
}
