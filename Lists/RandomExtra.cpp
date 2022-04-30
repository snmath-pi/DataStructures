#include<iostream>
#include<list>
#include<algorithm>
//or just use #include<bits/stdc++.h> like i do cause i'm lazy but make sure to precompile it as its rather slow
using namespace std; 
int main(){
	list<int>l1  ={1,2,2,3,3,3,4,4,4,4};
	list<int>l2 = {69,70,71} ;
	list<int>::iterator it=l1.begin();
	advance(it,3);//chaging position of the iterator i
	//l1.unique() -> removes repeated elements from the list l1
	l1.unique() ;
	for(int &x:l1){
		cout<<x<<" ";
	}
	cout<<"\n" ;
	//splice for inserting a list inside another list for a given position splice(position,list to be merged)
	l1.splice(it,l2) ;
	cout<<"New l1 after inserting l2 at position it(i.e = 3) : \n" ;
	for(int &x:l1){
		cout<<x<<" " ;
	}
	cout<<"\n" ;
	//another function which is swap() just use it as l1.swap(l2) for swapping the lists and their elements
	
}
