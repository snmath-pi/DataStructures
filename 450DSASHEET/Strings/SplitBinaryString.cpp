//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string s){
        //Write your code here
        int cnt0 = 0, cnt1 = 0, n = s.length(), mx = 0;
        for(int i=0; i<n; i++) {
            cnt0 += s[i] == '0';
            cnt1 += s[i] == '1';
            if(cnt0 == cnt1) {
                mx++;
                cnt0 = 0, cnt1 = 0;
            }
        }
        if(cnt0 == cnt1) {mx += cnt0 != 0; return mx;}
        else return -1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
