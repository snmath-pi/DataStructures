#include<bits/stdc++.h>
using namespace std ;
void CalculateSpan(vector<int> &a , int n , vector<int>&b){
	stack<int> s ;
	s.push(0) ;
	b[0] = 1 ; 
	for(int i=1; i<n; i++){
		while(!s.empty() && a[s.top() ] <= a[i]){
			s.pop() ;
		}
		b[i] = ((s.empty() ) ?i +1 : i - s.top()) ;
		s.push(i) ;
	}
}
void solve(){
	vector<int> a = {10, 4, 5, 90, 120, 80} ;
	vector<int> b(a.size())  ;
	CalculateSpan(a , a.size() , b) ;
	for(auto x:b ) cout << x << " " ;
	cout << "\n" ;

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
