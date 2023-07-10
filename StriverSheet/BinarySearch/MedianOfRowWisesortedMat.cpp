int cnt(vector<int> &a, int val) {
    int l = 0, r = a.size()-1;
    while(l <= r) {
        int mid = l + r >> 1;
        if(a[mid] > val) r = mid-1;
        else l = mid + 1;
    }
    return l;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int l = 1, r = 1e9;
    int n = A.size(), m = A[0].size();
    
    auto good = [&](int mid) {
        int tot = 0;
        for(int i=0; i<n; i++) {
            tot += cnt(A[i], mid);
        }
        return tot;
    };
    while(l <= r) {
        int mid = l + r >> 1;
        if(good(mid) <= (n * m) / 2) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
