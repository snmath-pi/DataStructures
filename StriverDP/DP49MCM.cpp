#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 1e9));
    for(int i=0; i<N; i++) dp[i][i] = 0;
    
    for(int i = N-1; i>=1; i--) {
        for(int j=i + 1; j<N; j++) {
            for(int k=i; k<j; k++) {
                dp[i][j] = min(dp[i][j], arr[i-1] * arr[j] * arr[k] + dp[i][k] + dp[k+1][j]);
            }
        }
    }
    return dp[1][N-1];
}
