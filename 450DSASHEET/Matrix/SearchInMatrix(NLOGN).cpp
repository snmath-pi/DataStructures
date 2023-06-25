class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int N = (int) a.size();
        int M = (int) a[0].size();
        int ans = -1;
        int L = 0, R = N-1;
        while(R >= L) {
            int MID = L + (R - L) / 2;
            if(a[MID][0] > target) {
                R = MID - 1;
                ans = MID;
            } else if(a[MID][0] < target) L = MID + 1;
            else if(a[MID][0] == target) return true;
        }        
        // // Finding upper_bound is a better idea,
        // Why you may ask?
        // Because if we find the lower_bound we are not certain whether the chosen row has the element > or = target but upper_bound is always a strict condition(>)!
        
        if(ans > 0) ans--;
        else if(ans == -1) ans = N - 1;
        L = 0 , R = M-1;
        while(R >= L) {
            int MID = L + (R - L) / 2;
            if(a[ans][MID] == target) return true;
            else if(a[ans][MID] < target) L = MID + 1;
            else R = MID - 1;
        }
        return false;
        
    }
};
