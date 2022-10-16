#include<bits/stdc++.h>
using namespace std ;
bool check(int node , vector<int>vis , vector<int> dfsvis , vector<int> adj[]){
	if(vis[node] == 0) vis[node] = 1 ;
	if(dfsvis[node] == 0) dfsvis[node] = 1; 

	for(auto x: adj[node]){
		if(!vis[x]){
			if(check(x , vis , dfsvis, adj)) return true ;
		}else if(dfsvis[x]){
			return true ;
		}
	}
	dfsvis[node] = 0 ;
	return false ;

}
bool directeddfs(int n , vector<int> adj[]){
	vector<int> vis ;
	vector<int>	dfsvis ;
	vis.resize(n) , dfsvis.resize(n) ;
	for(int i=0; i<n; i++){
		if(!vis[i]){
			if (check(i,vis,dfsvis,adj)) return true;
		}
	}
	return false ;
}
int main(){
	int n , m ;
	cin >> n >> m;
	vector<int> adj[n] ;
	for(int i=0; i<m; i++){
		int u , v ;
		cin >> u >> v ;
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;

	}
	if(directeddfs(n,adj)){
		cout << "YES\n" ;
	}
	else cout << "NO\n" ;
}
