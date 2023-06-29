class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size(), m = a[0].size();
        int l = 0, r = n - 1, search = -1;
        while(r >= l) {
            int mid = (l + r) >> 1;
            if(a[mid][0] == target) return true;
            else if(a[mid][0] < target) {
                l = mid + 1;
                search = mid;
            } else {
                r = mid - 1;
            }
        }
        if(search == -1) search = n - 1;
        l = 0, r = m - 1;
        while(r >= l) {
            int mid = (l + r) >> 1;
            if(a[search][mid] == target) {
                return true;
            } else if(a[search][mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
        
    }
};
