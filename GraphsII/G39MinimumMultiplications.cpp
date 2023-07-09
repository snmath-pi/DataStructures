//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dis(100000, 1e9);
        dis[start] = 0;
        const int mod = 1e5;
        if(start == end)return 0;
        while(!q.empty()) {
            auto it = q.front(); q.pop();
            int node = it.first, steps = it.second;
            for(auto &x: arr) {
                int val = (node % mod * x % mod) % mod;
                if(steps + 1 < dis[val]) {
                    
                    dis[val] = steps + 1;
                    if(val == end) return steps + 1;
                    q.push({val, dis[val]});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
