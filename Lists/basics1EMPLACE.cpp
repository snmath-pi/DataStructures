#include<iostream>
#include<list>
using namespace std ;
int main(){
	list<int> l;
	list<int>::iterator it = l.begin() ;
	for(int i=0;i<=2;++i){
		l.emplace_back(i);
	}
	cout<<"List after emplace_back :\n" ;
	for(int &x:l){
		cout<<x<<" " ;
	}
	cout<<"\n" ;
	for(int i=3;i<=33;i+=3){
		l.emplace_front(i) ;
	}
	cout<<"List after emplace_front :\n";
	for(int &x:l){
		cout<<x<<" " ;
	}
	cout<<"\n" ;
	advance(it,3) ;//used to move the iterator to a new position(here it's 3 ) from previous(which was l.begin()i.e1)
	l.emplace(it,3333);//pushes a 3333 at index 3 in list
	cout<<"List after emplace() is: \n";
	for(int &x:l){
		cout<<x<<" ";
	}
	cout<<"\n" ;

}
