#include<bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 10;
int64_t t[4*mxN];
vector<int64_t> a;
void build(int v, int l, int r) {
	if(l==r) {
		t[v] = a[l]; return;
	}
	int m = l + r >> 1;
	// so now we break and build 
	// if we number the root node as '1' then left child will be 2*i and right child will be 2*i+1
	build(2*v, l, m);
	build(2*v+1, m+1, r);
	t[v]=t[2*v]+t[2*v+1]; // it's sum equal to sum of it's two child's as we already saw
	// this construciton will take O(n) time
}

// now answering the queries
int64_t val(int v, int tl, int tr, int l, int r) {
	if(l>r) return 0ll;
	if(l==tl&&r==tr) {
		return t[v]; // this means we found the given range // or the current range 
	}
	int mid = tl + tr >> 1;
	return val(2*v,tl,mid, l, min(mid,r)) + val(2*v+1, mid+1,tr,max(l,mid+1), r);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// now this problem can also be done using simple prefix sums
	// something like
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
