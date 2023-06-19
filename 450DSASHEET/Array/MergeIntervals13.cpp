#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [&](vector<int>&a, vector<int>&b) {
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    vector<vector<int>> res;
    int m = (int)intervals.size();
    int f = intervals[0][0], s = intervals[0][1];
    for(int i=1; i<m; i++) {
        if(s >= intervals[i][0]) {
            s = max(s,intervals[i][1]);
        } else {
            vector<int> a; a.push_back(f),a.push_back(s);
            res.push_back(a);
            f = intervals[i][0], s = intervals[i][1];
        }
    }
    vector<int> a = {f, s};
    res.push_back(a);
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> intervals(N);

    for(int i=0; i<N; i++) {
        int L, R;
        cin >> L >> R;
        intervals[i].push_back(L);
        intervals[i].push_back(R);
    }
    
    vector<vector<int>> merged_intervals = merge(intervals);
    for(int i=0; i<merged_intervals.size(); i++) {
        cout << merged_intervals[i][0] << ' ' <<  merged_intervals[i][1] << '\n';
    }
}
