// Linked List Implementation of Stack
/*
 * author : math_pi
 * created: 2022-05-09 Mon 07:46 PM
*/
#include<bits/stdc++.h>
using namespace std ;
struct Node{
	int data; 
	Node* next ;
	Node(int d){
		data = d ;
		next = NULL ;

	}
};
struct MyStack{
	Node*head ;
	int sz ;
	MyStack(){
		head = NULL ; sz = 0 ;
	}
	void push(int x){
		Node*temp = new Node(x) ;
		temp->next = head ;
		head = temp ;
		sz++ ;
	}
	int pop(){
		if(head==NULL) return INT_MAX ; // To prevent Underflow in case of an empty stack 
		int res = head->data ;
		Node*temp = head ;
		head = head->next ;
		delete(temp) ;
		sz-- ;
		return res ;
	}
	int size(){
		return sz ;
	}
	bool isEmpty(){
		return head==NULL ;
	}
	int peek(){
		if(head==NULL) return INT_MAX ; //To prevent Underflow 
		return head->data ;
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
