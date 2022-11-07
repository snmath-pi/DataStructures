#include<bits/stdc++.h>
using namespace std ;
void PrintNextGreater(vector<int>&a , int n){
	stack<int> st ;
	st.push(a[0]) ;
	for(int i=1; i<n; i++){
		if(st.empty()){
			st.push(a[i]) ;
		}
		while(!st.empty() && a[i] > st.top()){
			cout << st.top() << "->" << a[i] << "\n" ;
			st.pop() ;
		}
		st.push(a[i]) ;
	}
	while(!st.empty()){
		cout << st.top() << "-> -1\n" ;
		st.pop() ;
	}
}
void solve(){
	vector<int> a = {11, 13, 21, 3} ;
	PrintNextGreater(a , a.size()) ;

}
int main(){
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int t = 1 ;
	// cin >> t ;
	while(t--){
		solve() ;
	}
}
