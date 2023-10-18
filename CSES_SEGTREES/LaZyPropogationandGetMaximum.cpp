#include<bits/stdc++.h>
using namespace std;

vector<int> a;
const int mxN = 2e5 + 10;
int64_t t[4*mxN];
int64_t lazy[4*mxN];

void push(int v) {
	t[v*2] += lazy[v];
	t[v*2+1] += lazy[v];
	lazy[v*2+1] += lazy[v];
	lazy[v*2] += lazy[v];
	lazy[v] = 0;
}
void build(int v, int tl, int tr) {
	if(tl==tr) t[v] = a[tl];
	else {
		int tm = tl + tr >> 1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = max(t[v*2],t[v*2+1]);
	}
}
void update(int v, int tl, int tr, int l, int r, int add) {
	if(l>r) return;
	if(tl==l && tr == r) {
		t[v] += add;
		lazy[v] += add;
	}
	else {
		push(v);
		int tm = tl + tr >> 1;
		update(v*2, tl, tm, l, min(tm, r), add);
		update(v*2+1, tm+1, tr, max(tm+1, l), r, add);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}

int64_t get(int v, int tl, int tr, int l, int r) {
	if(l>r) return -1e18;
	if(tl==l && tr == r) return t[v];
	push(v);
	int tm = tl + tr >> 1;
	return max(get(v*2, tl, tm, l, min(tm, r)), 
			   get(v*2+1, tm+1, tr, max(l, tm+1), r));
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
			int l, r, new_val; cin >> l >> r >> new_val;
			update(1, 0, n-1, --l, --r, new_val); // add this value to whole range
		} else {
			int l, r; cin >> l >> r; 
			cout << get(1, 0, n-1, --l, --r) << '\n'; // get max in range
		}
	}

}
