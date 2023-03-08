#include<iostream>
using namespace std;

int cnt = 1;
void f() {
	if(cnt == 11) return;
	else cout << cnt * 2 << "\n";
	cnt++;
	f();
}
int main() {
	f();
}
