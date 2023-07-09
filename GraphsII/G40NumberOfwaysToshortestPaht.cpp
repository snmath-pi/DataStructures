class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int64_t mod = 1e9 + 7;
        vector<vector<pair<int64_t, int64_t>>> g(n);
        for(auto &it: roads) {
            g[it[0]].push_back({it[1], it[2]});
            g[it[1]].push_back({it[0], it[2]});
        }
        vector<int64_t> dis(n, 1e18);
        vector<int64_t> dp(n, 0);
        dis[0] = 0, dp[0] = 1;
        priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int64_t d = it.first, node = it.second;
            for(auto &child: g[node]) {
                auto x = child;
                int64_t cur = x.second, v = x.first;
                if(dis[v] > d + cur) {
                    dis[v] = d + cur;
                    pq.push({dis[v], v});
                    dp[v] = dp[node];
                } else if(dis[v] == d + cur) {
                    dp[v] = (dp[v] + dp[node]) % mod;
                }
            }
        }
        return dp[n-1]%mod;

    }
};
