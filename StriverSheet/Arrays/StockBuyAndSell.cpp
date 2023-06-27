class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0, n = (int) prices.size();
        if(n == 1) return mx;
        int val = prices[0];
        for(int i=1; i<n; i++) {
            if(prices[i] > val) mx = max(mx, prices[i] - val);
            else if(prices[i] < val) val = prices[i];
        }
        return mx;
    }
};
