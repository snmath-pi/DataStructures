#include <bits/stdc++.h>
using namespace std;
struct Node {
	Node* len[2];

	bool contains(int x) {
		return len[x] != nullptr;
	}
	Node* get(int x) {
		return len[x];
	}
	void put(int x, Node* node) {
		len[x] = node;
	}
};

class Trie {
	private: Node *root;
public:
	Trie() {
		root = new Node();
	}
	void insert(int x) {
		Node *node = root;
		for(int i=31; i>=0; i--) {
			int bit = (x >> i) & 1;
			if(!node->contains(bit)) {
				node->put(bit, new Node());
			}
			node = node->get(bit);
		}
	}
	int mx_val(int x) {
		Node *node = root;
		int mx = 0;
		for(int i=31; i>=0; i--){
			int bit = (x >> i) & 1; 
			if(node->contains(!bit)) {
				mx += (1 << i);
				node = node->get(!bit);
			} else node = node->get(bit);

		}
		return mx;
	}

};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	int n = queries.size();
	vector<pair<int, pair<int, int>>> q;
	for(int i=0; i<n; i++) {
		q.push_back({queries[i][1], {queries[i][0], i}});
	}
	sort(q.begin(), q.end());
	sort(arr.begin(), arr.end());
	vector<int> res(n, 0);
	int i = 0;
	Trie trie;
	for(auto &x: q) {
		int ai = x.first, xi = x.second.first, idx = x.second.second;
		while(i < n && arr[i] <= ai) {
			trie.insert(arr[i++]);
		}
		if(i == 0) res[idx] = -1;
		else {
			res[idx] = trie.mx_val(xi);
		}
	}

	return res;
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n); 
	for(int i=0; i<n; i++) cin >> a[i];
	vector<vector<int>> queries(m, vector<int>(2));
	for(int i=0; i<m; i++) {
		cin >> queries[i][0] >> queries[i][1];
	}
	vector<int> res = maxXorQueries(a, queries);

	for(auto &x: res) cout << x << ' ';
}
