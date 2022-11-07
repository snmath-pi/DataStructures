#include<bits/stdc++.h>
using namespace std ;
void PrintNGF(vector<int>&a , int n , vector<int> &freq){
	stack<int> st ;
	st.push(0) ;
	int res[n] = {0} ;
	for(int i=1; i<n; i++){
		if(freq[a[i]] < freq[a[st.top()]]){
			st.push(i) ;
		}
		else{

			while(!st.empty() && freq[a[i]] > freq[a[st.top()]]){

				res[st.top()] = a[i] ;
				st.pop() ;
			}
			st.push(i) ;
		}
	}
	while(!st.empty()){
		res[st.top()] = -1 ;
		st.pop() ;
	}
	for(int i=0; i<n; i++) cout << res[i] << " \n"[i == n-1] ;

}
void solve(){
	vector<int> a = {1, 1, 2, 3, 4, 2, 1} ;
	int mx = *max_element(a.begin() , a.end()) ;
	vector<int> freq(mx+1 , 0)  ;
	for(int i=0; i<a.size(); i++){
		freq[a[i]]++ ;
	}
	//for(auto x:freq) cout << x << " " ;
	PrintNGF(a, a.size(), freq) ;

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
