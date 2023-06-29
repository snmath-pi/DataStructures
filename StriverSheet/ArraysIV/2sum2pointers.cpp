class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> a(n);
        for(int i=0; i<n; i++) a[i].first=nums[i], a[i].second = i;
        sort(a.begin(), a.end());
        vector<int> ans;
        for(int i=0, r = n-1; i < r; ) {
            if(a[i].first + a[r].first == target) {
                ans = {a[i].second, a[r].second};
                break;
            } else if(a[i].first + a[r].first < target) i++;
            else r--;
        }
        return ans;
    }
};
