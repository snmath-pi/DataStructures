#include<iostream>
#include<list>
using namespace std ;
int main(){
	list<int> l1 = {1,2,3,4,5,6,7} ;
	list<int> l2 = {9,10,11} ;
	l1.merge(l2) ;
	//notice both of them are in ascending order(basically sorted) so new list formed will also be sorted
	cout<<" A single list l1 formed after merging l1 and l2 : \n";
	for(int &x:l1){
		cout<<x<<" " ;
	}
	cout<<"\n" ;
	//using remove to remove all elements that are even
	l1.remove_if([] (int jj) {return !(jj&1) ;}) ;
	cout<<"List after using remove_if: \n" ;
	for(int &x:l1){
		cout<<x<<" " ;
	}
	cout<<"\n" ;
}
