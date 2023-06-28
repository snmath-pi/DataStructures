#include <bits/stdc++.h> 
int cnt(int n, vector<int> &heights, vector<int> &dp) {
    if(n == 0) return 0;
    if(dp[n]) return dp[n];

    int first = (n >= 1 ? cnt(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]) : 1e9);
    int second = (n >= 2 ? cnt(n-2, heights, dp) + abs(heights[n-2] - heights[n]) : 1e9);
    return dp[n] = min(first, second);

}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, 0);
    return cnt(n-1, heights, dp);
}
