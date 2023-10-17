#include<bits/stdc++.h>
using namespace std;
// The Range queries are solved using Lazy Propogration
// something like change / increase each value in range [l, r]
// then you are asked to return the value at position 'k'

const int mxN = 2e5+5;
int64_t t[4*mxN];
vector<int64_t> a;

void build(int v, int tl, int tr) {
	if(tl==tr) {
		t[v] = a[tl]; 
	}
	else {
		int tm = tl + tr >> 1;
		build(v*2, tl, tm); build(v*2+1, tm+1, tr); 
		t[v] = 0;
	}
}

void update(int v, int tl, int tr, int l, int r, int add) {
	if(l > r) return;
	if(l==tl && r == tr) {
		t[v] += add; return;
	}
	int tm = tl + tr >> 1;
	update(v*2, tl, tm, l, min(r, tm), add); update(v*2+1, tm+1, tr, max(l, tm+1), r, add);

}

int64_t res(int v, int tl, int tr, int pos) {
	if(tl==tr) return t[v];
	int tm = tl + tr >> 1;
	if(pos<=tm) return t[v] + res(v*2, tl, tm, pos);
	return t[v] + res(v*2+1, tm+1, tr, pos);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	a.resize(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	build(1, 0, n-1);
	for(int i=0; i<q; i++) {
		int type; cin >> type;
		if(type==1) {
			int l, r, add; cin >> l >> r >> add;
			update(1, 0, n-1, --l, --r, add);
		} else {
			int k; cin >> k;
			cout << res(1, 0, n-1, --k) << '\n';
		}
	}


}
