#include<bits/stdc++.h>
using namespace std;

// merging k sorted arrays
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k; cin >> k;
	vector<vector<int>> x(k);

	for(int i=0; i<k; i++) {
		x[i].resize(k-i);
		for(int j=i; j<k; j++) {
			cin >> x[i][j-i];
		}
	}
	// storing value, i, i(id)
	priority_queue<array<int,3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
	for(int i=0; i<k; i++) pq.push({x[i][0], i, 0});
	
	vector<int> res;
	while(!pq.empty()) {
		auto [val, i, id] = pq.top(); pq.pop();
		res.push_back(val);
		if(id + 1 < x[i].size()) pq.push({x[i][id + 1], i, id + 1});
	}

	for(auto &x: res) {
		cout << x << ' ';
	}


}
