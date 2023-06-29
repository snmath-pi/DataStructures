class Solution {
public:
    long long dfs2(int l,  int mid, int r, vector<int> &a) {
        vector<int> temp(r - l + 1);
        int i = l, j = mid, k = 0, inv = 0;
        while(i < mid) {
            while((j <=r && a[i] > 2ll * a[j])) j++;
            inv += (j - mid);
            i++;
        }
        i = l, j = mid;
        while((i < mid) && (j <= r)) {
            if(a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                temp[k++] = a[j++];
            }
        }
        while(i < mid) temp[k++] = a[i++];
        while(j <= r) temp[k++] = a[j++];
        for(int i=l, k =0; i <= r; i++, k++) a[i] = temp[k];
        return inv;
    }
    int dfs(int l, int r, vector<int> &nums) {
        long long  iv = 0;
        if(l < r) {
            int mid = (l + r) >> 1;
            iv += dfs(l, mid, nums);
            iv += dfs(mid + 1, r, nums);
            iv += dfs2(l, mid + 1, r, nums);
        }
        return iv;
    }
    int reversePairs(vector<int>& nums) {
        return dfs(0, nums.size()-1, nums);
    }
};
