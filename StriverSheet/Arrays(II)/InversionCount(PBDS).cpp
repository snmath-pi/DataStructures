#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long inv = 0;
    ordered_set s;
    for(int i=n-1; i>=0; i--) {
        if(!s.empty()) {
            inv += s.order_of_key(arr[i]);
        } 
        s.insert(arr[i]);
    }
    return inv;
}
