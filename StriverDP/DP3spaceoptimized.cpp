#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev = 0, prev2 = 0;
    for(int i=1; i<=n; i++) {
        int curi = min(prev + abs(heights[i-1] - heights[i]), (i > 1 ? prev2 + abs(heights[i-2] - heights[i]) : INT_MAX));
        prev2 = prev;
        prev = curi;
    }
    return prev2;
}
