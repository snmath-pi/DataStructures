import java.util.* ;
import java.io.*; 
public class Solution {
    private static long func(long[] arr, int ll, int mm, int rr) {
        long[] tempo; tempo = new long[rr - ll + 1];
        int i = ll, j = mm, k = 0;

        long inv_ = 0;
        while((i < mm) && (j <= rr)) {
            if(arr[i] <= arr[j]) {
                tempo[k++] = arr[i++];
            } else {
                inv_ += (mm - i);
                tempo[k++] = arr[j++];
            }
        }
        while(i < mm) tempo[k++] = arr[i++];
        while(j <= rr) tempo[k++] = arr[j++];
        for(int u = ll, v = 0; u <= rr; u++, v++) {
            arr[u] = tempo[v];
        }

        return inv_;
    }
    private static long dfs(long[] arr, int l, int r) {
        long total_inv = 0;
        if(l < r) {
            int m = l + r >> 1;
            total_inv += dfs(arr, l, m);
            total_inv += dfs(arr, m + 1, r);
            total_inv += func(arr, l, m + 1, r);
        }

        return total_inv;
    }
    public static long getInversions(long arr[], int n) {
        // Write your code here.

        return dfs(arr, 0, n - 1);
    }
}
