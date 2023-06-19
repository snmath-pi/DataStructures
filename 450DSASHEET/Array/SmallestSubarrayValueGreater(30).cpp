#include<bits/stdc++.h>
using namespace std;
int smallestSubWithSum(int a[], int n, int x)
{
        // Your code goes here   
        long long sum = 0; int j = 0;
        int mn = n;
        for(int i=0; i<n; i++) {
            sum += a[i];
            if(sum > x) {
                while(j < n && sum - a[j] > x) sum -= a[j], j++;
                mn = min(mn, i - j + 1);
            }
        }
        return mn;
}
int main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    cout << smallestSubWithSum(a, n, x) << '\n';
}
