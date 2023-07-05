//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        cout << setprecision(2) << fixed;
        sort(arr, arr + n, [&](Item &x, Item &y) {
            return ((long double)x.value / (long double) x.weight) > ((long double)y.value / (long double)y.weight); 
        });
        int cur = 0;
        long double val = 0.0;
        for(int i = 0; i<n; i++) {
            if(arr[i].weight + cur <= W) {
                val += arr[i].value;
                cur += arr[i].weight;
            } else {
                long double can_take = W - cur;
                long double frac = can_take / arr[i].weight;
                val += arr[i].value * frac;
                break;
            }
        }
        return val;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
