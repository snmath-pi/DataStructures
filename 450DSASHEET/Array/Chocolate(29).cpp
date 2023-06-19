#include <bits/stdc++.h>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int64_t> A(N);
    for(int i=0; i<N; i++) 
        std::cin >> A[i];

    int64_t mx = 1e18;
    std::sort(A.begin(), A.end());
    for(int i=0; i<N - M + 1; i++) {
        mx = std::min(mx, A[i + M - 1] - A[i]);
    }
    std::cout << mx << '\n';
}
