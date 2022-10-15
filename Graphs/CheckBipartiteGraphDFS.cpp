#include<bits/stdc++.h>
using namespace std ;
bool bipartitedfs(int i , int color[] , vector<int> adj[]){
	if(color[i] == -1) color[i] = 1 ;
	for(auto x: adj[i]){
		if(color[x] == -1){
			color[x] = 1 - color[i] ;
			if(!bipartitedfs(x , color , adj)){
				return false ;
			}else if(color[x] == color[i]) return false ;
		}
	}
	return true ;
}
bool checkBipartite(vector<int> adj[] , int n){
	int color[n] ;
	memset(color , -1 , sizeof(color)) ;
	for(int i=0; i<n; i++){
		if(color[i] == -1){
			if(!bipartitedfs(i , color , adj)){
				return false ;
			}
		}
	}
	return true; 
}
int main() {
	int n , m ;
	cin >> n >> m;
	vector<int> adj[n] ;
	for(int i=0; i<m; i++){
		int u , v ;
		cin >> u >> v ;
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;
	}
	if(checkBipartite(adj,n)){
		cout << "yes" << "\n" ;

	}
	else cout << "no" << "\n" ;
}
