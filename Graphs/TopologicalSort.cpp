#include<bits/stdc++.h>
using namespace std; 
void printsort(int i , vector<int> &vis , vector<int> adj[] , stack<int>&s){
	vis[i] = 1 ;
	for(auto x:adj[i]){
		if(!vis[i]){
			printsort(x , vis,adj,s) ;
		}
	}
	s.push(i) ;


}
void topologicalSort(int n , vector<int> adj[]){
	vector<int> vis(n, 0) ;
	stack<int> s ;
	for(int i=0; i<n; i++){
		if(!vis[i]){
			printsort(i , vis , adj ,s);
		}
	}
	vector<int> topo ;
	while(!s.empty()){
		topo.push_back(s.top()) ;
		s.pop() ;
	}
	for(auto x:topo) cout << x << " " ;
}
int main(){
	int n , m ;
	cin >> n >> m ;
	vector<int> adj[n] ;
	for(int i=0; i<m; i++){
		int u , v; 
		cin >> u >> v; 
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;
	}
	topologicalSort(n , adj);
}
