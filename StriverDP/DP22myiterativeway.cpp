long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    long long dp[value + 1] = {0};
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=1; j<= value; j++) {
            if(j >= denominations[i]) dp[j] += dp[j-denominations[i]];
        }
    }
    return dp[value];
}
