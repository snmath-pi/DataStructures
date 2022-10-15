void dfs(int i , vector<int>&vis , vector<int> adj[] , vector<int> &v){
	v.push_back(i) ;
	vis[i] = 1 ;
	for(auto it : adj[i]){
		if(!vis[it]){
			vis[it] = 1 ;
			dfs(it , vis , adj , v) ;
		}
	}
}

vector<int> DFS(int V , vector<int> adj[]){

	vector<int> StoreDfs ;
	vector<int> vis(V,0) ;
	for(int i=1; i<V; i++){
		if(!vis[i]){
			dfs(i , vis	,adj, StoreDfs) ;
		}
	} 
	return StroeDfs ;
}
