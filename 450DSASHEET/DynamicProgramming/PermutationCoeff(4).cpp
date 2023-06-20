#include<bits/stdc++.h>
using namespace std;

int64_t factorials[200050];
constexpr int mod = 1e9 + 7;

void calc() {
    factorials[0] = 1;
    for(int i=1; i<200050; i++) factorials[i] = i  *factorials[i-1] % mod;
    return;
}

// method 1 O(N * K) time and space
// P(N, K) = P(N-1, K) + K * P(N-1, K-1)

int64_t M1(int N, int K) {
    int64_t P[N+1][K+1];


    for(int i=0; i<=N; i++) {
        for(int j=0; j <= min(i, K); j++) {
            if(!j) P[i][j] = 1;
            else P[i][j] = (P[i-1][j] + j * P[i-1][j-1]) % mod;
            P[i][j+1] = 0;

        }
    }
    return P[N][K];
}
int64_t M2(int N, int K) {
    return factorials[N] / factorials[N-K];
}
int main() {
    int N, K;
    cin >> N >> K;
    calc();
    cout << M1(N, K) << '\n';

    cout << M2(N, K) << '\n';

    // or we can use the fact that P(N, K)  = n * (n-1) * (n-2) ... * (n - k + 1)
    int64_t ans = 1;
    for(int i=0; i < K; i++) {
        ans = ans * (N-i) % mod;
    }
    cout << ans << '\n';
}
