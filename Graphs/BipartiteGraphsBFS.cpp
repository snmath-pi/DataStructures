#include<bits/stdc++.h>
using namespace std ;
bool bipartitedfs(int i , vector<int> adj[] , int color[]){
	queue<int> q ;
	color[i] = 1 ;
	q.push(i) ;
	while(!q.empty()){
		int node = q.front() ;
		q.pop() ;
		for(auto x: adj[node]){
			if(color[x] == -1){
				color[x] = 1 - color[node] ;
				q.push(x) ;
			}
			else if(color[x] == color[node]){
				return false ;
			}
		}
	}
	return true ;
}
bool checkBipartite(int n , vector<int> adj[]){
	int color[n] ;
	memset(color , -1 , sizeof(color))  ;
	for(int i=0; i<n; i++){
		if(color[i] == -1){
			if(!bipartitedfs(i , adj , color)){
				return false ;
			}
		}

	}
	return true ;

}
int main() {
	int n , m ;
	cin >> n >> m ;
	vector<int> adj[n] ;
	for(int i=0; i<m; i++){
		int u , v ;
		cin >> u >> v; 
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;

	}
	if(checkBipartite(n , adj)) return 1;
	else return 0 ;
	
}
