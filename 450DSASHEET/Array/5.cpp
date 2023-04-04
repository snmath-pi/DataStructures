#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;
 
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    // sort(all(a)) -> this is one method when order doesn't matter
    // what if we need in place?
    // can we do better in O(N)
    /*

    // THIS IS INPLACE PARTITION ORDER IN MAINTAINED
    int j = 0;
    rep(i, n) {
        if(a[i] < 0) {
            if(i!=j) {
                swap(a[i], a[j]);
            }
            j++;
        }
    }
    for(auto x: a) cout << x << ' ';
    */

    /*TWO POINTERS
    int j= n-1;
    for(int i=0; i <= j; ) {
        if(a[i] < 0 && a[j] < 0) {i++;}
        else if(a[i] < 0 && a[j] > 0) {j--; i++;}
        else if(a[i] > 0 && a[j] < 0) {swap(a[i], a[j]); i++; j--;}
        else if(a[i] >0 && a[j] > 0) {j--;}
    }

    rep(i, n) cout << a[i] << ' ';
    */

    
    // DUTCH NATIONAL FLAG ALGO
    // int l =0, r = n-1;
    // while(l < r) {
    //     if(a[l] < 0) {
    //         l++;
    //     } else if(a[r] > 0) {
    //         r--;
    //     } else {
    //         swap(a[l], a[r]);
    //     }
    // }

    // rep(i, n) cout << a[i] << ' ';
    

}
