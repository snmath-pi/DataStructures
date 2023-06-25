//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        string res = "";
        int mx = 0, len;
        int l, h, n = s.length(), prev = -1;
        string a = "", b = "";
        for(int i=0; i<n; i++) {
            l = i-1, h = i, len = 0;
            a = "", b ="";
            while(l>=0 && h < n && s[l] == s[h]) l--, h++;
            l++, h--;
            len = h - l + 1;
            a = s.substr(l, len);
            if(len > mx) {
                res = a;
                mx = len; 
            } 
            
            l = i-1, h = i + 1, len = 0;
            a = "", b = "";
            while(l >= 0 && h < n && s[l] == s[h]) l--, h++;
            l++, h--;
            len = h - l + 1;
            a = s.substr(l, len);
            if(len > mx) {
                res = a; mx = len;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
