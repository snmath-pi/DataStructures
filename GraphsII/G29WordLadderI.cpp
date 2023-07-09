class Solution {
public:
   
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size() + 1;
        vector<vector<int>> g(n);
        for(int j=0; j<n-1; j++) {
            string x = wordList[j];
            if(x.size() != beginWord.size()) continue;
            int one = 0;
            for(int i=0; i<x.size(); i++) {
                if(beginWord[i] != x[i]) one++;
            } 
            if(one == 1) {
                g[0].push_back(j+1);
                g[j+1].push_back(0);
            }
        }
        for(int j=0; j<wordList.size(); j++) {
            for(int i=j+1; i<wordList.size(); i++) {
                string x = wordList[j], y = wordList[i];
                if(x.size()!=y.size())continue;
                int one = 0;
                for(int k = 0; k<x.size(); k++) {
                    if(x[k] != y[k]) one++; 
                }
                if(one == 1) {
                    g[j+1].push_back(i+1);
                    g[i+1].push_back(j+1);
                }
            }
        }
        vector<int> dis(n, 1e9);
        dis[0] = 0;
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q; q.push(0);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(auto &child: g[node]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    q.push(child);
                    dis[child] = dis[node] + 1;
                }
            }
        }
        int end = -1;
        for(int j=0; j<wordList.size(); j++) {
            if(wordList[j] == endWord) {
                end = j + 1;
                break;
            }
        }
        if(end == -1) return 0;
        return (dis[end] == 1e9 ? 0 : dis[end] + 1);
        

    }
};
