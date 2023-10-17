#include<bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 10;
int64_t t[4*mxN];
vector<int64_t> a;
void build(int v, int tl, int tr) {
	if(tl==tr) {
		t[v]=a[tl];
	} else {
		int tm = tl + tr >> 1;
		build(v*2, tl, tm); build(v*2+1, tm+1, tr);
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

int64_t val(int v, int tl, int tr, int l, int r) {
	if(l>r) return 1e18;
	if(tl==l&&tr==r) return t[v];
	int tm = tl + tr >> 1;	
	return min(val(2*v, tl, tm, l, min(tm, r)), val(2*v+1, tm+1, tr, max(l, tm+1), r));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k; 
	cin >> n >> k;
	a.resize(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	build(1, 0, n-1);
	for(int i=0; i<k; i++) {
		int l, r; cin >> l >> r; 
		cout << val(1, 0, n-1, --l, --r) << '\n';
	}

}
