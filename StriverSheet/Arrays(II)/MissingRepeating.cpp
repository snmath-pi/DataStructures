vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = (int)A.size();
    long long a = n *1ll* (n + 1) / 2;
    long long b = (n *1ll* (n + 1) * (2 * n + 1)) / 6;
    for(int i=0; i<n; i++) {
        a -= (long long) A[i];
        b -= ((long long) A[i] * (long long) A[i]);
    }
    int x = (b - (a * a)) / (2 * a);
    int y = a + x;
    return {x, y};
    
    
}
