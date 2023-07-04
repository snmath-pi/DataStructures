class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int lmax = 0, rmax = 0, water = 0;
        for(int l=0, r = n-1; l < r; ) {
            if(a[l] <= a[r]) {
                if(a[l] >= lmax) lmax=a[l++];
                else water += lmax - a[l++];
                
            } else {
                if(a[r] >= rmax) rmax = a[r--];
                else water += rmax - a[r--];
            }
        }
        return water;
    }
};
