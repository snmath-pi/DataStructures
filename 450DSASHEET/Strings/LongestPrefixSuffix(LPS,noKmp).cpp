//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int ans = 0, n = s.length();
	    if(n == 1) return ans;
	    deque<char> a, b;
	    for(int i=0; i<n-1; i++) a.push_back(s[i]);
	    for(int i=1; i<n; i++) b.push_back(s[i]);
	    if(a == b) {return n - 1;}
	    int cnt = n - 1;
	    while(!a.empty()) {
	        a.pop_back(); b.pop_front();
	        cnt--;
	        if(a == b) ans = max(ans, cnt);
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends
