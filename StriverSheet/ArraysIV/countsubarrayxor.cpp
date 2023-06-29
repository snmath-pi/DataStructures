int Solution::solve(vector<int> &A, int B) {
    map<int64_t, int> mp;
    int64_t ans = 0;
    for(int64_t i = 0, xr = 0; i < A.size(); i++) {
        xr ^= A[i];
        if(mp.find(xr ^ B) != mp.end()) ans += mp[xr ^ B];
        if(xr == B) ans++;
        mp[xr]++;
    }
    return ans;
}

