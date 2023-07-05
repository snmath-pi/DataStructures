//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    struct comp {
        bool operator()(Job const&a, Job const&b) {
            return a.profit < b.profit;
        }
    };
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        vector<int> res(2, 0);
        sort(arr, arr + n, [&](Job &a, Job &b) {
            return a.dead < b.dead; 
        });
        priority_queue<Job, vector<Job>, comp> pq;
        int left;
        for(int i=n-1; i>=0; i--) {
            if(i == 0) left = arr[i].dead;
            else left = arr[i].dead - arr[i-1].dead; pq.push(arr[i]);
            while(left && !pq.empty()) {
                Job job = pq.top();
                pq.pop();
                res[0]++;
                res[1] += job.profit;
                left--;
            }
            
        }
        return res;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
