#include<bits/stdc++.h>
using namespace std;


void add(int &x, int y) {
    x |= (1 << y);
}
void remove(int &x, int y) {
    x ^= (1 << y);
}
void display(int subset) {
    for(int i=9; i>=0; i--) {
        cout << (((subset >> i) & 1) != 0) << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int subset = 15;
    display(subset);
    remove(subset, 3);
    display(subset);

    add(subset, 7);
    display(subset);

}
