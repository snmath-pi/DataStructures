#include<bits/stdc++.h>
using namespace std;
// declaring basic structure of a NODE
struct Node{
	int data ;
struct Node*next ;
} *first=NULL ; //first pointer declared globally
void create(int a[] , int n){
	int i ;
	struct Node*t , *last ;
	first = new Node() ;
	first->data = a[0] ;
	first->next = NULL ;
	last = first ;
	for(int i=1;i<n;++i){
		t= new Node() ;
		t->data = a[i] ;
		t->next = NULL ;
		last->next = t ;
		last = t ;

	}
	
}
void display(struct Node*p){
	while(p){                      //print the linked list until p==NULL / (p!=0) or (p) .
		printf("%d " , p->data) ;
		p = p->next ; // shifting the previous pointer to next pointer of the list;

	}
	cout<<"\n" ;

}
int main(){
	int a[] = {1,2,3,4,5} ;
	int n = sizeof(a)/sizeof(a[0]) ;
	create(a,n) ;
	display(first) ;

}
