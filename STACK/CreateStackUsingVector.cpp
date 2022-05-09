// Vector Implementation of Stack
/*
 * author : math_pi
 * created: 2022-05-09 Mon 07:46 PM
*/
#include<bits/stdc++.h>
using namespace std ;
struct MyStack{
	vector<int> v ;
	void push(int x){
		v.push_back(x) ;
	}
	int pop(){
		int res = v.back() ;
		v.pop_back() ;
		return res ;
	}
	int size(){
		return v.size() ;
	}
	bool isEmpty(){
		return v.empty() ;
	}
	int peek(){
		return v.back() ;
	}
}; 
int main(){
	MyStack s ;
	s.push(5); s.push(10) ;s.push(20) ;
	cout<<s.pop()<<"\n" ;     	//(20 removed) // (10,5) 
	cout<<s.size()<<"\n" ;		//(2)
	cout<<s.peek()<<"\n" ;		//(10)
	cout<<s.isEmpty()<<"\n" ;	//(0) i.e False 
	return 0 ;

}
