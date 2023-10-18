#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
const int mxN = 1e3 + 10;
int t[4*mxN][4*mxN];
int n, q; 

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
	if(ly == ry) {
		if(lx == rx) t[vx][vy] = a[lx][ly];
		else {
			t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
		}
	} else {
		int my = ly + ry >> 1;
		build_y(vx, lx, rx, vy*2, ly, my);
		build_y(vx, lx, rx, vy*2+1, my+1, ry);
		t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
	}
}
void build_x(int vx, int lx, int rx) {
	if(lx!=rx) {
		int mx = lx + rx >> 1;
		build_x(vx*2, lx, mx);
		build_x(vx*2+1, mx+1, rx); 
	} 
	build_y(vx, lx, rx, 1, 0, n-1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
	if(ly>ry) return 0;
	if(ly==tly && ry==try_) {
		return t[vx][vy];
	}
	int tmy = tly + try_ >> 1;
	return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)) 
			+ sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}
int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if(lx>rx) return 0;
	if(lx==tlx && rx==trx) 
		return sum_y(vx, 1, 0, n-1, ly, ry);
	int tmx = tlx + trx >> 1;
	return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry) + 
		   sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	a = vector<vector<int>>(n, vector<int>(n));

	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		char c; cin >> c; a[i][j] = (c=='*');
	}

	build_x(1, 0, n-1);
	for(int i=0; i<q; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2; --y1, --x1, --y2, --x2;
		cout << sum_x(1, 0, n-1, y1, y2, x1, x2) << '\n';

	}

}
