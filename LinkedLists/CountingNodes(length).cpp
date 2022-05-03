#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data ;
struct Node*next ;
} *first=NULL ;
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
	while(p){
		printf("%d " , p->data) ;
		p = p->next ;

	}
	cout<<"\n" ;

}
//USING RECURSION FOR PRINTING THE ELEMENTS OF THE LINKED LIST 
void RDisplay(struct Node*p){
	if(p!=NULL){
		printf("%d ", p->data) ;
		RDisplay(p->next) ;
		
	}

}
//USING RECURSION FOR PRINTING ELEMENTS IN REVERSED OREDER
void RRDisplay(struct Node*p){
	if(p!=NULL){
		RRDisplay(p->next) ;
		printf("%d ",p->data) ;
	}
}
// Function to return no. of nodes i.e length of the linked list
int Count(struct Node*p){
	int cnt(0) ;
	while(p){
		p=p->next; 
		cnt++ ;
	}
	return cnt ;
}
int main(){
	int a[] = {1,2,3,4,5} ;
	int n = sizeof(a)/sizeof(a[0]) ;
	create(a,n) ;
	cout<<Count(first) ;
	

	//RDisplay(first) ;
	//cout<<"\n" ;
	//RRDisplay(first) ;
	cout<<"\n" ;


}
