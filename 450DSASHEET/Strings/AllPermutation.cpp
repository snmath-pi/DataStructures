//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
        set<string> res;
        void permute(string &s, int l, int r) {
            if(l == r) res.insert(s);
            else {
                for(int i=l; i<=r; i++) {
                    swap(s[l],s[i]);
                    permute(s, l + 1, r);
                    swap(s[l], s[i]);
                }
            }
        }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    permute(S, 0, S.size()-1); 
		    vector<string> ans;
		    for(auto &x: res) ans.push_back(x);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
