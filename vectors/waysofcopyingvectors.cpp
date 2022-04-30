#include<iostream>
#include<vector>
using namespace std; 
int main(){
	vector<int> v1{1,2,3,4} ;
	vector<int>v2 = v1 ;
	for(int i=0;i<v2.size();++i){
		cout<<v2[i]<<" " ;
	}
	vector<int>v3(v1) ;
	cout<<"\n" ;
	for(auto x=0;x<v3.size();++x){
		cout<<v3[x]<<" "; 
	}
	cout<<"\n" ;
	vector<int> v4 ;
	copy(v1.begin() ,v1.end(),back_inserter(v4)); 
	for(int i=0;i<v4.size();++i){
		cout<<v4[i]<<" " ;
	}
	cout<<"\n" ;
	vector<int>v5 ;
	v5.assign(v1.begin(),v1.end() );
	for(int i=0;i<v5.size();++i){
		cout<<v5[i]<<" " ;

	}
	cout<<"\n" ;
	
}
