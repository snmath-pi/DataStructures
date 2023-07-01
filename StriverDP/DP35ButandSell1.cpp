#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mx_profit = 0, mn = 1e9;
    for(int i=0; i<prices.size(); i++) {
        if(prices[i] < mn) {
            mn = prices[i];
        } else {
            mx_profit = max(mx_profit, prices[i] - mn);
        }
    }
    return mx_profit;
}
