#include<bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 10;
int64_t t[4*mxN];
vector<int64_t> a;

void build(int v, int tl, int tr) {
	if(tl == tr) {
		t[v] = a[tl]; return;
	}
	int tm = tl + tr >> 1;
	build(v*2, tl, tm); build(v*2+1, tm+1, tr);
	t[v] = min(t[v*2], t[v*2+1]);
}

int64_t val(int v, int tl, int tr, int l, int r) {
	if(l>r) return 1e18;
	if(tl==l && tr==r) return t[v];
	int tm = tl + tr >> 1;
	return min(val(v*2, tl, tm, l, min(r,tm)), val(v*2+1, tm+1, tr, max(tm+1, l), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if(tl==tr) {
		t[v] = new_val; return;
	}
	int tm = tl + tr >> 1;
	if(pos<=tm) update(v*2, tl, tm, pos, new_val);
	else update(v*2+1, tm+1, tr, pos, new_val);
	t[v] = min(t[v*2], t[v*2+1]);
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
	// okay so now we have two types of queries i.e dynmaic range sum
	// we have the general query of answering the sum for range [l, r]
	// in addition to this we have another query to change a[k] = some given value;
	// we just need to add update funciton and keep updating values going upwards in the tree
	build(1, 0, n-1);
	for(int i=0; i<q; i++) {
		int type; cin >> type;
		if(type==1) {
			int pos, new_val; cin >> pos >> new_val;
			update(1, 0, n-1, --pos, new_val);
		} else {
			int l, r; cin >> l >> r;
			cout << val(1, 0, n-1, --l, --r) << '\n';
		}
		
	}

}
