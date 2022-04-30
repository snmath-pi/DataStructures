#include<iostream>
#include<queue>
#include<algorithm>
using namespace std ;
int main(){
	queue<int> q;
	q.push(3) ;
	q.push(33) ;
	
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop() ;
		
	}
	cout<<"\n" ;
	//Some Functions
	cout << "\nq.size() : " << q.size();
    cout << "\nq.front() : " << q.front();
    cout << "\nq.back() : " << q.back();
	
}
