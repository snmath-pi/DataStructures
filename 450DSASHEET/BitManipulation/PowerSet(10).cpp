//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    #define all(x) (x).begin(), (x).end()

		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.size();
            vector<string> res;
            for(int mask = 1; mask < (1 << n); mask++) {
                string temp = "";
                for(int i=0; i<n; i++) {
                    if((1 << i) & mask) temp += s[i];
                }
                res.push_back(temp);
            }
            sort(all(res));
            return res;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
