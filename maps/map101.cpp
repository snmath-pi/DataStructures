#include<iostream>
#include<map>
#include<vector>
#include<functional>
using namespace std; 
#define pb push_back
#define mp make_pair
int main(){
	map<string, vector<int>, greater<string>> lol ;
	lol["saksham"].push_back(1);
	lol["saksham"].push_back(1);
	lol["saksham"].push_back(1);
	lol["sasham"].push_back(2);
	lol["sakham"].push_back(3);
	lol["ssham"].push_back(4);
	for(auto x:lol){
		cout<<x.first<<"\n ";
		for(auto x2:x.second)
			cout<<x2<<" " ;
		cout<<"\n" ;
	}


}
