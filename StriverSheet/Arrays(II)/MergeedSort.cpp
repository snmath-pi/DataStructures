class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
        int i = n-1, j = m - 1, k = n + m - 1;
        while(j >= 0) {
            if(i >= 0 && a[i] > b[j]) a[k--] = a[i--];
            else a[k--] = b[j--];
        }
    }
};
