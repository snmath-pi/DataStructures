//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool good(int id, int n, vector<int> &color, bool graph[101][101], int i) {
        for(int k=0; k<n; k++) {
            if(k!=id && graph[k][id] == 1 && color[k] == i) return false;
        }
        return true;
    }
    bool solve(int id, int m, int n, bool graph[101][101], vector<int> &color) {
        if(id == n) {
            return true;
        }
        for(int i=1; i<=m; i++) {
            if(good(id, n, color, graph, i)) {
                color[id] = i;
                if(solve(id + 1, m, n, graph, color)) return true;;
                color[id] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n, 0);
        return solve(0, m, n, graph, color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
