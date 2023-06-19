//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(__builtin_popcount(N) != 1) return -1;
        int cnt = 0;
        while(N) N/=2,cnt++;
        return cnt;
      // also a fact that if only one bit is set the number is a power of 2 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
