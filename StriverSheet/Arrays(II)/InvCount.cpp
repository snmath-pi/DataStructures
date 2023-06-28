#include <bits/stdc++.h> 

long long getInversions(long long *arr, int n){
    // Write your code here.
    auto Ihatecoding = [&](int l, int m, int r) {
        long long inv = 0;
        vector<int> temp(r - l + 1);
        int i = l, j = m, k = 0;
        while((i < m) && j <= r) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv += m - i;
            }
        }
        while(i < m) temp[k++] = arr[i++];
        while(j <= r) temp[k++] = arr[j++];
        for(int i=l, k =0; i <= r; i++, k++) arr[i] = temp[k];
        return inv;
    };
    function<long long(int, int)> ans = [&](int l, int r) {
        long long res = 0;
        if(r > l) {
            int m = l + r >> 1;
            res += ans(l, m);
            res += ans(m + 1, r);
            res += Ihatecoding(l, m + 1, r);
        }  
        return res;
    };
    return ans(0, n-1);
}
