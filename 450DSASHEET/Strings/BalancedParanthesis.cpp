//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        int n = x.length();
        map<char, char> mp;
        mp.insert({'(', ')'}); mp.insert({'[', ']'}); mp.insert({'{', '}'});
        for(int i=0; i<n; i++) {
            if(!s.empty()) {
                if(mp[s.top()] == x[i]) {
                    s.pop();continue;
                } else s.push(x[i]);
            }
            else s.push(x[i]);
        }
        return s.empty() == true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
