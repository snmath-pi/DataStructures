#include<iostream>
#include<stack>
using namespace std ;
int prec(char c){
	if(c == '+' || c == '-')
		return 1 ;
	else if(c == '*' || c == '/')
		return 2 ;
	else if(c == '^')
		return 3 ;
	else
		return -1 ;

}
void infixtopostfix(string s ){
	string lmao  ;
	stack<char> sus ;
	for(int i= 0 ;i<s.size() ; i++){
		char c = s[i] ;

		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')){
			lmao += c ;
		}
		else if(c == '(')
			sus.push(c) ;
		else if(c == ')'){
			while(sus.top()!= '('){
				lmao += sus.top() ;
				sus.pop() ;
			}
			sus.pop() ;
		}
		else{
			while(!sus.empty() && prec(c) <= prec(sus.top())){
				lmao += sus.top() ;
				sus.pop() ;

			}
			sus.push(c) ;
		}
	}
	while(!sus.empty()){
		lmao += sus.top() ;
		sus.pop() ;
	}
	cout << lmao ;

}
int main(){
	string s = "a+b*(c^d-e)^(f+g*h)-i" ;
	infixtopostfix(s) ;
}
