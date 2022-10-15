vector<int> bfsOfGraph(int V , vector<int> &adj[]){
	
	vector<int> visited(V+1,0); 
	vector<int> ans ;
	queue<int> q ;
	for(int i=1; i<=V; i++){
		if(!visited[i]){
			visited[i] = true ;
			q.push(i) ;
			while(!q.empty()){
				int x = q.front()
				q.pop() ;
				ans.push_back(x) ;
				for(auto i: adj[x]){
					if(!visited[i]){
						visited[i] = true ;
						q.push(i) ;

					}
				}
			}
		}
	}
	return ans ;

}
