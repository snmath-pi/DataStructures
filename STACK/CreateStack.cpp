#include<bits/stdc++.h>
using namespace std ;
struct MyStack{
	int *arr ;
	int cap ;
	int top ;
	MyStack(int c){
		cap = c ;
		arr = new int[cap] ;
		top = -1 ;

	}
	void push(int x){
		top++ ;
		arr[top] = x ;
	}
	int pop(){
		int res = arr[top] ;
		top-- ;
		return res ;
	}
	int peek(){
		return arr[top] ;
	}
	int size(){
		return(top+1) ;
	}
	bool isEmpty(){
		return (top==-1) ;
	}
} ;
int main(){
	MyStack s(5) ; //array of length 5(0,1,2,3,4) is created is Stack Fashion ;
	s.push(5); s.push(10) ;s.push(20) ;
	cout<<s.pop()<<"\n" ;     	//(20 removed) // (10,5) 
	cout<<s.size()<<"\n" ;		//(2)
	cout<<s.peek()<<"\n" ;		//(10)
	cout<<s.isEmpty()<<"\n" ;	//(0) i.e False 
	return 0 ;


}
