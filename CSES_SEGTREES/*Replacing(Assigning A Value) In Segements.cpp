#include<bits/stdc++.h>
using namespace std;

vector<int> a;
const int mxN = 2e5 + 10;
int64_t t[4*mxN];
bool marked[4*mxN];

void push(int v) {
	if(marked[v]) {
		t[v*2] = t[v*2+1] = t[v];
		marked[v*2] = marked[v*2+1] = true;
		marked[v] = false;
	}
}
void build(int v, int tl, int tr) {
	if(tl==tr) t[v] = a[tl];
	else {
		int tm = tl + tr >> 1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = 0;
	}
}
void update(int v, int tl, int tr, int l, int r, int new_val) {
	if(l>r) return;
	if(tl==l && tr == r) {
		t[v] = new_val;
		marked[v] = true;
	}
	else {
		push(v);
		int tm = tl + tr >> 1;
		update(v*2, tl, tm, l, min(tm, r), new_val);
		update(v*2+1, tm+1, tr, max(tm+1, l), r, new_val);
	}
}

int64_t get(int v, int tl, int tr, int pos) {
	if(tl==tr) return t[v];
	push(v);
	int tm = tl + tr >> 1;
	if(pos <= tm) {
		return get(v*2, tl, tm, pos);
	}
	return get(v*2+1, tm+1, tr, pos);
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
			update(1, 0, n-1, --l, --r, new_val);
		} else {
			int k; cin >> k;
			cout << get(1, 0, n-1,--k) << '\n';
		}
	}

}
