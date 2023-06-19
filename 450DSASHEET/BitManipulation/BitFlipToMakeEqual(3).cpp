//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int cnt =0;
        for(int i=0; i<31; i++) {
            cnt += (((1<<i) & a) == 0 && ((1<<i)&b) != 0 || (((1<<i))&a) != 0 && ((1<<i)&b) == 0);
        }
        return cnt;
        
    }
    int countBitsFlipusingGCC(int a, int b){
        
        // Your logic here
        int y = a ^ b;
        return __builtin_popcount(y);
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}
// } Driver Code Ends
