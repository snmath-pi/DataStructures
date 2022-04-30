#include<iostream>
#include<deque>
#include<algorithm>
using namespace std ;
int main(){
	deque<int> dq;
	dq.push_front(3) ;//pushes element at front of the queue
	dq.push_back(33) ;//pushes element at the back -> 3,33
	dq.push_back(444) ;//->3,33,444
	dq.push_front(333) ;//->333,3,33,444
	deque<int>::iterator it;
	for(it=dq.begin();it!=dq.end();++it){
		cout<<" "<<*it<<" ";
	}
	cout<<"\n" ;
	//Some Functions
	cout << "\ngquiz.size() : " << dq.size();
    cout << "\ngquiz.max_size() : " << dq.max_size();
 
    cout << "\ngquiz.at(2) : " << dq.at(2);
    cout << "\ngquiz.front() : " << dq.front();
    cout << "\ngquiz.back() : " << dq.back();
	
}
