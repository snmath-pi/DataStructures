#include<iostream>
#include<vector>
#include<queue>
using namespace std ;
vector<int> bfsTraversal(int V , vector<int> adj[]){
	vector<int> bfs ;
	vector<bool> vis(V , 0) ;
	for(int i=0; i<V; i++){
		if(!vis[i]){
			queue<int> q ;
			vis[i] = 1 ;
			q.push(i) ;
			while(!q.empty()){
				int node = q.front() ;
				q.pop() ;
				bfs.push_back(node) ;
				for(auto it:adj[node]){
					if(!vis[it]){
						q.push(it) ;
						vis[it] = 1;
					}
				}
			}


		}
	}
	return bfs ;

}
int main(){
	int n , m;
	cin >> n >> m ;
	vector<int> adj[m] ;
	for(int i=0; i<n; i++){
		int u , v ;
		cin >> u >> v ;
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;
	}
	bfsTraversal(n , adj) ;

}
