#include "bits/stdc++.h"
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
	vector<int> ndp(m, 0);
	auto fun = [&]() {
		stack<int> s;
		int mx = 0;
		for(int i=0; i<=m; i++) {
			while(!s.empty() && (i == m || ndp[s.top()] >= ndp[i])) {
				int height = ndp[s.top()];
				s.pop();
				int width;
				if(s.empty()) width = i;
				else width = i - s.top() - 1;
				mx = max(mx, width * height);
			}
			s.push(i);
		}  
		return mx;
    };
	int res = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(mat[i][j] == 1) ndp[j]++; 
			else ndp[j] = 0;
		}
		res = max(res, fun());
	}

	return res;


}
