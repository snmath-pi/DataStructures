//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    
    int maxArea(int a[MAX][MAX], int n, int m) {
        // Your code here
    
        vector<int> cur_area(m);
        int mx_area = 0;
        auto fun = [&]() {
            stack<int> s;
            int mx = 0;
            for(int i=0; i<=m; i++) {
                while(!s.empty() && (i == m || cur_area[s.top()] >= cur_area[i])) {
                    int height = cur_area[s.top()];
                    s.pop();
                    int width;
                    if(s.empty()) width = i;
                    else width = i - s.top() - 1;
                    mx = max(mx, width * height);
                }
                s.push(i);
            }  
            return mx;
        };
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j] == 1) cur_area[j]++;
                else cur_area[j] = 0;
            }
            mx_area = max(mx_area, fun());
        }
        return mx_area;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
