class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& ot) {
        vector<vector<int>> a(n);
        for(int i=0; i<ot.size(); i++) {
            a[ot[i][0]].push_back(ot[i][1]);
        }
        queue<int> q;
        vector<int> in(n, 0);
        for(int i=0; i < n; i++) {
            for(int x: a[i]) {
                in[x]++;
            }
        }
        for(int i=0; i<n; i++) {
            if(in[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop(); cnt++;
            for(auto child: a[node]) {
                in[child]--;
                if(in[child] == 0) q.push(child);
            }
        }
        return cnt == n;
    }
};
