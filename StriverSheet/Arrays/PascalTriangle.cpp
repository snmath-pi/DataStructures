class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        // base case for n = 1
        vector<int> dp = {1}; res.push_back(dp);
        if(n == 1) return res; int m;
        
        for(int i=0; i<n-1; i++) {
            vector<int> ndp; 
            ndp.push_back(dp[0]); 
            /*
            process is something like this 
                    1
                   1 1
                  1 2 1
                  basically what we are doing is storing the first value -> storing adjacent sums -> storing end value
                  (stored 1, stored 1 + 1, stored 1)
                
                */
            m = (int)dp.size();
            for(int j=0; j<m-1; j++) ndp.push_back(dp[j] + dp[j+1]);
            ndp.push_back(dp[m-1]);
            res.push_back(ndp); // push this result
            swap(dp, ndp); // swap the arrays or just assign them (dp = ndp) but swapping is a little faster 
        }
        return res;
    }
};
