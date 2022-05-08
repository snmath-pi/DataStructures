//math_pi
//******

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
int Count(struct Node*p){
	int cnt(0) ;
	while(p){
		p=p->next; 
		cnt++ ;
	}
	cout<< cnt ;
}
int CountR(struct Node*p){
	if(!p) return 0 ;
	else {
		return CountR(p->next)+1 ;
	}
}
int Sum(struct Node*p){
	int sum(0) ;
	while(p){
		sum+=p->data ;
		p = p->next ;
	}
	return sum ;
}
// TO PRINT MAXIMUM ELEMENT
int MAX(struct Node*p){
	int maxx = INT_MIN ;
	while(p){
		if(p->data>maxx) maxx = p->data ;
		p=p->next ;
	}
	return maxx ;
}
struct Node * Lsearch(struct Node*p , int key){
	struct Node*q =NULL ;
	while(p){
		if(key==p->data){
			q->next = p->next ;
			p->next = first ;
			first = p ;
			return p ;
		}
		q = p ;
		p=p->next ;

	}
	return NULL ;

}
//INSERTING AT A GIVEN POSITION( HEAD OR ANY OTHER POSITION) 
void Insert(struct Node*p, int pos ,int x){
	Node* t ;
	t = new Node ;
	t->data = x ;
	if(pos==0){ //CHECKING IF THE POSITION IS THE HEAD POSITION
		t->next = first ;
		first =t ;

	}
	else {
		
		for(int i=0;i<pos-1 ;++i) p = p->next ; 					
		t->next = p->next ;
		p->next = t ;
	}
}
void InsertLast(int x ){
	Node * last ;
	Node*t = new Node;
	t->data = x ;
	t->next = NULL ; 
	if(first==NULL)
		first=last=t;
	else{
		last->next =t ;
		last = t;
	}


}
void InsertSortedLL(struct Node*p , int x){
	struct Node * q = NULL	 ;
	Node*t = new Node;
	t->data = x ;
	t->next = NULL ;
	if(first==NULL){
		first = t ;
	}
	else{

		while(p && p->data<x){
			q = p;

			p = p->next;

		

		}
		if(p==first){
			t->next = first; 
			first = t ;

		}
		else{
			t->next = q->next; 
			q->next =t ;
		}

	}
	

}
//CHECKING IF LINKED LIST IS SORTED 
int sorted(struct Node*p){
	int x = -65536 ;
	while(p){
		if(p->data<x){
			return 0 ;
		}
		x =p->data ;
		p = p->next ;
	}
	return 1 ;
	

}
int main(){
	int a[] = {1,2,3,4,13} ;
	int n = sizeof(a)/sizeof(a[0]) ;
	create(a,n) ;
	cout<<sorted(first) ;		

	cout<<"\n" ;

}
