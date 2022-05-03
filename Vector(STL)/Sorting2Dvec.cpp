#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool sizecom(const vector<int>&v1,const vector<int>&v2){
	return v1.size()<v2.size() ;
}
int main(){
	vector<vector<int>>v1{{3,3},{4,5,6},{10}};
	cout<<"Vector Matrix before sorting :\n" ;
	for(int i=0;i<v1.size();++i){
		for(int j=0;j<v1[i].size();++i){
			cout<<v1[i][j]<<" ";
			
		}
		cout<<"\n" ;
	}
	//sort function for ascending order : 
	sort(v1.begin(),v1.end(),sizecom); 
	cout<<"Vector Matrix after sorting by ascending order wrt columns :\n" ;
	for(int i=0;i<v1.size();++i){
		for(int j=0;j<v1[i].size();++i){
			cout<<v1[i][j]<<" ";
		}
		cout<<"\n" ;
	}
}
