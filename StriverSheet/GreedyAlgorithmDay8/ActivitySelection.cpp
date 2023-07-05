//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> a;
        for(int i=0; i<n; i++) a.push_back({start[i], end[i]});
        sort(a.begin(), a.end(), [](pair<int, int> &x, pair<int, int> &y) {
            return x.second < y.second;
        });
        int taken = 1;
        int cur_max = a[0].second;
        for(int i=1; i<n; i++) {
            if(a[i].first > cur_max) {
                cur_max = a[i].second;
                taken++;
            }
        }
        return taken;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
