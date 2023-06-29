class Solution {
public:
    double myPow(double x, long long n) {
        long double res = 1.0;
        long long y = n; n *= -1;
        while(n) {
            if(n & 1) res = res * x;
            x = x * x;
            n /= 2;
        }
        return (y < 0 ? 1 / res : res);
    }
};
