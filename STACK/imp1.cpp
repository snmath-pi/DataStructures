#include<iostream>

using namespace std ;
class Stack{
private:
	static const int MAX = 100 ;
	int top ;
	int ar[MAX] ;
public:
	Stack() {top = -1 ;}
	bool isempty() ;
	bool isfull() ;
	void push(int n);
	int pop() ;

};
bool Stack::isempty(){
	if(top == -1)
		return true ;
	return false ;
}
bool Stack::isfull(){
	if(top == MAX - 1){
		return true ;
	}
	return false ;
}
void Stack::push(int n){
	if(isfull()){
		cout << "Stack Overflow UwU" ;
	}
	ar[++top] = n ;
}
int Stack::pop(){
	if(isempty()){
		cout << "The Stack is empty dummy O-O" ;
	}
	return ar[top--] ;


}
int main(){
	Stack stack ;
	stack.push(4) ;
	stack.push(1) ;
	stack.push(3) ;
	stack.push(5) ;
	cout << stack.pop();
}

