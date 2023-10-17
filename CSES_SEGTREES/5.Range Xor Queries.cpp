#include<bits/stdc++.h>
using namespace std;
 
vector<int64_t> a;
const int mxN = 3e5 + 10;
int64_t t[4*mxN];
void build(int v, int tl, int tr) {
	if(tl==tr) {
		t[v] = a[tl]; return;
	}
	int tm = (tl+tr)/2;
	build(v*2, tl, tm); build(v*2+1, tm+1, tr);
	t[v] = t[v*2]^t[v*2+1];
}
int64_t XOR(int v, int tl, int tr, int l, int r) {
	if(l > r) return 0;
	if(tl==l && tr == r) return t[v];
	int tm = (tl+tr)/2;
	return (XOR(v*2, tl, tm, l, min(tm, r)) ^ XOR(v*2+1, tm+1, tr, max(l, tm+1), r));
 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, k; cin >> n >> k;
	a.resize(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	build(1, 0, n-1);
	for(int i=0; i<k; i++) {
		int l, r; cin >> l >> r;
		cout << XOR(1, 0, n-1, --l, --r) << '\n';
	}
 
}
