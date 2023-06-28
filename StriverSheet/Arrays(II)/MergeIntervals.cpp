class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int start_with = intervals[0][0], end_with = intervals[0][1];
        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= end_with) {
                end_with = max(end_with, intervals[i][1]);
            } else {
                vector<int> temp;
                temp.push_back(start_with); temp.push_back(end_with);
                res.push_back(temp);
                start_with = intervals[i][0], end_with = intervals[i][1];
            }
        }
        vector<int> temp; temp.push_back(start_with); temp.push_back(end_with);
        res.push_back(temp);
        return res;
        
    }
};
