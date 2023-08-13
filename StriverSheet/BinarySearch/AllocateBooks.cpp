int Solution::books(vector<int> &A, int B) {
        
        int l = *max_element(A.begin(), A.end())-1, r = 2e9;
        int n = A.size();
        if(n < B) return -1;
        auto good = [&](int m) {
            int sum = 0;
            int cnt = 1;
            for(int i=0; i<n; i++) {
                if(sum + A[i] <= m) sum += A[i];
                else {
                    cnt++;
                    sum = A[i];
                }
            }
            return cnt <= B;
        };
        while(r > l + 1) {
            int m = l + r >> 1;
            if(good(m)) r = m;
            else l = m;
        }
        return r;
}
