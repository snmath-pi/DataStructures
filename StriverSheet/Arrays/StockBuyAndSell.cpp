class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0, n = (int) prices.size();
        if(n == 1) return mx;
        int val = prices[0];
        // basic greedy + simulation
        // simulate what they say
        // if price value > val in hand store price[i] - val as it will always be profitable
        // other wise if price val < val this means we found a smaller starting(buying value) and it's always better to have smaller buying value 
        // proof by contradiction: CLAIM->let's say we have a buying value X and Y (X > Y) and we get more profit by buying X
        // let's say currently we decide to sell the stock for value  = Z
        // hence the profit = Z - X & Z - Y
        // in this case since X > Y -> Z - X < Z - Y -> profit(X) < profit(Y)
        // this contradicts our fact that we get more profit by buying X
        // hence proved
        for(int i=1; i<n; i++) {
            if(prices[i] > val) mx = max(mx, prices[i] - val);
            else if(prices[i] < val) val = prices[i];
        }
        return mx;
    }
};
