// Balanced Paranthesis in a String
// Check if Paranthesis is balanced 
// Condition:
//1. Brackets () {} [] must close 
//2. Bracket entered in the last must be filled first
/*
 * author : math_pi
 * created: 2022-05-09 Mon 09:05 PM
*/
#include<bits/stdc++.h>
using namespace std ;
bool matching(char a ,char b){
	if((a=='(' && b==')') || (a=='{'&& b=='}') || (a=='['&& b==']')) return true ;
	return false;	
}
bool isBalanced(string s){
	stack<int> ss ;
	for(int i=0;i<s.size();++i){
		if(s[i]=='(' || s[i]=='{' || s[i]=='[' ) ss.push(s[i]) ;
		else{
			if(ss.empty()) return false; 
			else if(!matching(ss.top(),s[i])) return false; 
			else ss.pop() ;
		}
	}
	return (s.empty()==true) ;
}
 
int main(){
	string s ;
	cin>>s ;
	cout<<isBalanced(s)<<"\n"  ;


}
/*#include<bits/stdc++.h>
using namespace std ;
bool isBalanced(string s){
	stack<char> st ;
	
	for(int i=0; i<s.size(); i++){
		char c = s[i] ;
		if(st.empty()){
			st.push(c) ;
		}
		else if((st.top()== '(' && c== ')')  || (st.top()== '{' && c== '}') || (st.top() == '[' && c==']')) {
			st.pop() ;
		}
		else {
			st.push(c) ;
		}
	}
	return st.empty()  ;
}
void solve(){
	string s = "((()))" ;
	cout << ((isBalanced(s))?"YES\n":"NO\n")  ;

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
*/
