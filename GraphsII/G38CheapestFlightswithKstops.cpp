class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> g(n);
        for(int i=0; i<flights.size(); i++) {
            g[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dis(n, 1e9);
        q.push({0, {src, 0}});
        dis[src] = 0;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first, node = it.second.first, d = it.second.second;
            if(steps > k) {
                continue;
            }
            for(auto &child: g[node]) {
                auto it = child;
                int adjnode=  it.first;
                int cost = it.second;
                if(cost + d < dis[adjnode] && k >= steps) {
                    dis[adjnode] = cost + d;
                    q.push({steps + 1, {adjnode, dis[adjnode]}});
                }
            }
        }

        return (dis[dst] == 1e9 ? -1 : dis[dst]);



    }
};
